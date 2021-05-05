#pragma once
#include "3rd_party/oxygine-framework/oxygine/oxygine-include.h"
#include "3rd_party/oxygine-framework/oxygine/Event.h"
#include "3rd_party/oxygine-framework/oxygine/EventDispatcher.h"
#include "3rd_party/oxygine-framework/oxygine/Property.h"
#include "3rd_party/oxygine-framework/oxygine/UpdateState.h"
#include "3rd_party/oxygine-framework/oxygine/closure/closure.h"
#include "3rd_party/oxygine-framework/oxygine/core/Object.h"
#include "3rd_party/oxygine-framework/oxygine/utils/intrusive_list.h"
#include <limits>

namespace oxygine
{
    class TweenEvent : public Event
    {
    public:
        enum
        {
            START = sysEventID('S', 'T', 'A'),
            DONE = Event::COMPLETE,
        };

        TweenEvent(Tween* tween_, const UpdateState* us_) : Event(DONE, false), tween(tween_), us(us_) {}
        Actor* getActor() const;

        Tween* tween;
        const UpdateState* us;
    };



    const qint32 TWEEN_COMPLETE_DT = std::numeric_limits<int>::max() / 2;


    DECLARE_SMART(Tween, spTween);
    class Tween : public EventDispatcher, public intrusive_list_item<Tween>
    {
        typedef intrusive_list_item<Tween> intr_list;
    public:
        enum EASE
        {
            ease_unknown,
            ease_linear,

            ease_inQuad,
            ease_outQuad,
            ease_inOutQuad,
            ease_outInQuad,

            ease_inCubic,
            ease_outCubic,
            ease_inOutCubic,
            ease_outInCubic,

            ease_inQuart,
            ease_outQuart,
            ease_inOutQuart,
            ease_outInQuart,

            ease_inQuint,
            ease_outQuint,
            ease_inOutQuint,
            ease_outInQuint,

            ease_inSin,
            ease_outSin,
            ease_inOutSin,
            ease_outInSin,

            ease_inExpo,
            ease_outExpo,
            ease_inOutExpo,
            ease_outInExpo,

            ease_inCirc,
            ease_outCirc,
            ease_inOutCirc,
            ease_outInCirc,

            ease_inBack,
            ease_outBack,
            ease_inOutBack,
            ease_outInBack,

            ease_inBounce,
            ease_outBounce,
            ease_inOutBounce,
            ease_outInBounce,

            ease_count
        };

        Tween();
        ~Tween();

        void init(timeMS duration, qint32 loops = 1, bool twoSides = false, timeMS delay = timeMS(0), EASE ease = Tween::ease_linear);//todo twoSide find better name
        void init2(const TweenOptions& opt);
        /**if you reset internal Tween state it could be reused and added to actor again */
        void reset();

        qint32                  getLoops() const { return _loops; }
        timeMS                  getDuration() const { return _duration; }
        void                    setElapsed(const timeMS &elapsed);
        timeMS                  getElapsed() const { return m_elapsed; }
        EASE                    getEase() const { return _ease; }
        EASE                    getGlobalEase() const { return _globalEase; }
        timeMS                  getDelay() const { return _delay; }
        Actor*                  getClient() const { return m_client; }
        float                   getPercent() const { return _percent; }
        spObject                getDataObject() const { return _data; }
        spTween                 getNextSibling() { return intr_list::getNextSibling(); }
        spTween                 getPrevSibling() { return intr_list::getPrevSibling(); }
        const EventCallback&    getDoneCallback() const { return m_cbDone; }

        bool        isStarted() const { return _status != status_not_started; }
        bool        isDone() const { return _status == status_remove; }

        /**set custom user data object to Tween. Could be used for store some useful data*/
        void setDataObject(spObject data) { _data = data; }
        /**add callback would be called when tween done.  Could be added more than one.
        setDoneCallback is faster because it doesn't allocate memory for list internally*/
        void addDoneCallback(const EventCallback& cb);
        /**set Easing function*/
        void setEase(EASE ease) { _ease = ease; }
        /**set Global Easing function */
        void setGlobalEase(EASE ease) { _globalEase = ease; }
        /**set Delay before starting tween*/
        void setDelay(timeMS delay) { _delay = delay; }
        /** loops = -1 means infinity repeat cycles*/
        void setLoops(qint32 loops) { _loops = loops; }
        /*set Duration of tween**/
        void setDuration(timeMS duration) { _duration = duration; }
        void setClient(Actor* client) { m_client = client; }
        void setTwoSides(bool ts) { _twoSides = ts; }

        /** remove actor from parent node when tween done*/
        void detachWhenDone(bool detach = true) { _detach = detach; }

        /**immediately completes tween, calls doneCallback and mark tween as completed and removes self from Actor. If tween has infinity loops (=-1) then do nothing*/
        virtual void complete(timeMS deltaTime = timeMS(TWEEN_COMPLETE_DT));

        /**removes self from Actor, complete callback not called*/
        void removeFromActor();

        void start(Actor& actor);
        void update(Actor& actor, const UpdateState& us);

        static float calcEase(EASE ease, float v);
        typedef float (*easeHandler)(EASE ease, float v);
        static void  setCustomEaseHandler(easeHandler);

        /**set callback when tween done. Doesn't allocate memory. faster than addDoneCallback*/
        void setDoneCallback(const EventCallback& cb);
        /**set callback when tween done. Doesn't allocate memory. faster than addDoneCallback*/
        void setStartCallback(const EventCallback& cb);

        /** tween will freeze on 100% and never complete  */
        void setDisabledStatusDone(bool disabled) { _disabledStatusDone = disabled; }
    private:
        void __start(Actor& actor, const UpdateState& us);

    protected:
        void done(Actor&, const UpdateState& us);

        virtual void _start(Actor&) {}
        virtual void _update(Actor&, const UpdateState&) {}
        virtual void _done(Actor&, const UpdateState&) {}
        virtual void _loopDone(Actor&, const UpdateState&) {}
        virtual float _calcEase(float v);

        enum status
        {
            status_not_started,
            status_delayed,
            status_started,
            status_done,
            status_remove,
        };
        status _status;
        timeMS m_elapsed;

        timeMS _duration;
        timeMS _delay;
        qint32 _loops;
        qint32 _loopsDone;
        EASE _ease;
        EASE _globalEase;
        bool _twoSides;
        bool _disabledStatusDone;

        float _percent;
        bool _detach;

        EventCallback m_cbStart;
        EventCallback m_cbDone;
        Actor* m_client;

        spObject _data;
    };

    template<class GS>
    class TweenT;
    template<class GS>
    using spTweenT = oxygine::intrusive_ptr<TweenT<GS>>;

    template<class GS>
    class TweenT : public Tween
    {
    public:
        typedef typename GS::type type;

        TweenT(const GS& gs) : m_gs(gs) {}

        void _update(Actor& actor, const UpdateState& us)
        {
            type& t = *safeCast<type*>(&actor);
            m_gs.update(t, _percent, us);//todo fix cast
        }

        void _start(Actor& actor)
        {
            type& t = *safeCast<type*>(&actor);
            m_gs.init(t);
            UpdateState us;
            us.iteration = -1;
            m_gs.update(t, _calcEase(0.0f), us);
        }

        void _done(Actor& actor, const UpdateState&)
        {
            type& t = *safeCast<type*>(&actor);
            m_gs.done(t);
        }

        GS& getGS() { return m_gs; }

    private:
        GS m_gs;
    };


    template <typename GS>
    spTweenT<GS> createTween(const GS& gs, timeMS duration, qint32 loops = 1, bool twoSides = false, timeMS delay = oxygine::timeMS(0), Tween::EASE ease = Tween::ease_linear)
    {
        spTweenT<GS> p = spTweenT<GS>::create(gs);
        p->init(duration, loops, twoSides, delay, ease);
        return p;
    }

    template <typename GS>
    spTweenT<GS> createTween2(const GS& gs, const TweenOptions& opt)
    {
        spTweenT<GS> p = spTweenT<GS>::create(gs);
        p->init2(opt);
        return p;
    }

    DECLARE_SMART(TweenObj, spTweenObj);
    class TweenBase
    {
    public:
        typedef Actor type;
        virtual void init(Actor&) {}
        virtual void done(Actor&) {}
        virtual void update(Actor&, float, const UpdateState&) {}
    };

    DECLARE_SMART(TweenObj, spTweenObj);
    class TweenObj : public TweenBase, public Object
    {
    };

    template<class TTween>
    class TweenProxy
    {
    public:
        typedef Actor type;

        TweenProxy(intrusive_ptr<TTween> o) { _obj = o; }
        void init(Actor& a) { _obj->init(a); }
        void done(Actor& a) { _obj->done(a); }
        void update(Actor& a, float p, const UpdateState& us) { _obj->update(a, p, us); }

        intrusive_ptr<TTween> _obj;
    };
}


