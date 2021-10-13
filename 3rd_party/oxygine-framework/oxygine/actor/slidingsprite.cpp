#include "3rd_party/oxygine-framework/oxygine/actor/slidingsprite.h"

namespace oxygine
{

    SlidingSprite::SlidingSprite()
    {
        for (auto & sprite : m_sprites)
        {
            sprite = spSprite::create();
            addChild(sprite);
        }
    }

    void SlidingSprite::setResAnim(ResAnim* pAnim)
    {
        if (pAnim != nullptr)
        {
            for (auto & sprite : m_sprites)
            {
                sprite->setResAnim(pAnim);
                sprite->setWidth(pAnim->getWidth());
                sprite->setHeight(pAnim->getHeight());
            }
            m_sprites[0]->setPosition(0, 0);
            m_sprites[1]->setPosition(pAnim->getWidth(), 0);
            m_sprites[2]->setPosition(0, pAnim->getHeight());
            m_sprites[3]->setPosition(pAnim->getWidth(), pAnim->getHeight());
        }
    }

    float SlidingSprite::getSpeedX() const
    {
        return m_speedX;
    }

    void SlidingSprite::setSpeedX(float speed)
    {
        m_speedX = speed;
    }

    float SlidingSprite::getSpeedY() const
    {
        return m_speedY;
    }

    void SlidingSprite::setSpeedY(float speed)
    {
        m_speedY = speed;
    }

    bool SlidingSprite::getFlippedX() const
    {
        return m_flippedX;
    }

    void SlidingSprite::setFlippedX(bool flipped)
    {
        m_flippedX = flipped;
        for (auto & sprite : m_sprites)
        {
            sprite->setFlippedX(flipped);
        }
    }

    void SlidingSprite::update(const UpdateState& us)
    {
        if (m_speedX != 0.0f)
        {
            float speed = -m_speedX;
            if (m_flippedX)
            {
                speed = m_speedX;
            }
            for (auto & sprite : m_sprites)
            {
                sprite->setX(sprite->getX() + speed);
            }

            if (speed > 0)
            {
                if (m_sprites[0]->getX() >= getWidth())
                {
                    m_sprites[0]->setX(m_sprites[1]->getX() - m_sprites[0]->getWidth());
                    m_sprites[2]->setX(m_sprites[3]->getX() - m_sprites[2]->getWidth());
                }
                if (m_sprites[1]->getX() >= getWidth())
                {
                    m_sprites[1]->setX(m_sprites[0]->getX() - m_sprites[1]->getWidth());
                }
                if (m_sprites[2]->getX() >= getWidth())
                {
                    m_sprites[2]->setX(m_sprites[3]->getX() - m_sprites[2]->getWidth());
                }
                if (m_sprites[3]->getX() >= getWidth())
                {
                    m_sprites[3]->setX(m_sprites[2]->getX() - m_sprites[3]->getWidth());
                }
            }
            else
            {
                if (m_sprites[0]->getX() + m_sprites[0]->getWidth() < 0)
                {
                    m_sprites[2]->setX(m_sprites[3]->getX() + m_sprites[2]->getWidth());
                }
                if (m_sprites[1]->getX() + m_sprites[1]->getWidth() < 0)
                {
                    m_sprites[1]->setX(m_sprites[0]->getX() + m_sprites[0]->getWidth());
                }
                if (m_sprites[2]->getX() + m_sprites[2]->getWidth() < 0)
                {
                    m_sprites[2]->setX(m_sprites[3]->getX() + m_sprites[2]->getWidth());
                }
                if (m_sprites[3]->getX() + m_sprites[3]->getWidth() < 0)
                {
                    m_sprites[3]->setX(m_sprites[2]->getX() + m_sprites[2]->getWidth());
                }
            }            
        }

        if (m_speedY != 0.0f)
        {
            for (auto & sprite : m_sprites)
            {
                sprite->setY(sprite->getY() + m_speedY);
            }

            if (m_speedY > 0)
            {
                if (m_sprites[0]->getY() >= getHeight())
                {
                    m_sprites[0]->setY(m_sprites[1]->getY() - m_sprites[0]->getHeight());
                }
                if (m_sprites[1]->getY() >= getHeight())
                {
                    m_sprites[1]->setY(m_sprites[0]->getY() - m_sprites[1]->getHeight());
                }
                if (m_sprites[2]->getY() >= getHeight())
                {
                    m_sprites[2]->setY(m_sprites[3]->getY() - m_sprites[2]->getHeight());
                }
                if (m_sprites[3]->getY() >= getHeight())
                {
                    m_sprites[3]->setY(m_sprites[2]->getY() - m_sprites[3]->getHeight());
                }
            }
            else
            {
                if (m_sprites[0]->getY() + m_sprites[0]->getHeight() < 0)
                {
                    m_sprites[0]->setY(m_sprites[1]->getY() + m_sprites[1]->getHeight());
                }
                if (m_sprites[1]->getY() + m_sprites[1]->getHeight() < 0)
                {
                    m_sprites[1]->setY(m_sprites[0]->getY() + m_sprites[0]->getHeight());
                }
                if (m_sprites[2]->getY() + m_sprites[2]->getHeight() < 0)
                {
                    m_sprites[2]->setY(m_sprites[3]->getY() + m_sprites[2]->getHeight());
                }
                if (m_sprites[3]->getY() + m_sprites[3]->getHeight() < 0)
                {
                    m_sprites[3]->setY(m_sprites[2]->getY() + m_sprites[2]->getHeight());
                }
            }
        }
        ClipRectActor::update(us);
    }
}
