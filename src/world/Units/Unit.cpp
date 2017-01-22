// License: MIT

#include "Unit.h"

void Unit::setCombatFlag(bool enabled)
{
    if (enabled)
    {
        SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_COMBAT);
    }
    else
    {
        RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_COMBAT);
    }
}

bool Unit::isInCombat() const
{
    return m_combatStatus.isInCombat();
}

bool Unit::isAttacking(Unit* target) const
{
    ASSERT(target);

    return m_combatStatus.isAttacking(target);
}

void Unit::enterCombat()
{
    setCombatFlag(true);

    if (!hasStateFlag(UF_ATTACKING))
    {
        addStateFlag(UF_ATTACKING);
    }
}

void Unit::leaveCombat()
{
    setCombatFlag(false);

    if (hasStateFlag(UF_ATTACKING))
    {
        clearStateFlag(UF_ATTACKING);
    }

    if (IsPlayer())
    {
        reinterpret_cast<Player*>(this)->UpdatePotionCooldown();
    }
}

void Unit::onDamageDealt(Unit* target)
{
    ASSERT(target);

    m_combatStatus.onDamageDealt(target);
}

void Unit::addHealTarget(Unit* target)
{
    ASSERT(target != nullptr);

    if (target->IsPlayer())
    {
        m_combatStatus.addHealTarget(reinterpret_cast<Player*>(target));
    }
}

void Unit::removeHealTarget(Unit* target)
{
    ASSERT(target != nullptr);

    if (target->IsPlayer())
    {
        m_combatStatus.removeHealTarget(reinterpret_cast<Player*>(target));
    }
}

void Unit::addHealer(Unit* healer)
{
    ASSERT(healer != nullptr);

    if (healer->IsPlayer())
    {
        m_combatStatus.addHealer(reinterpret_cast<Player*>(healer));
    }
}

void Unit::removeHealer(Unit* healer)
{
    ASSERT(healer != nullptr);

    if (healer->IsPlayer())
    {
        m_combatStatus.removeHealer(reinterpret_cast<Player*>(healer));
    }
}

void Unit::addAttacker(Unit* attacker)
{
    ASSERT(attacker);

    m_combatStatus.addAttacker(attacker);
}

bool Unit::hasAttacker(uint64_t guid) const
{
    return m_combatStatus.hasAttacker(guid);
}

void Unit::removeAttacker(Unit* attacker)
{
    ASSERT(attacker != nullptr);
    ASSERT(IsInWorld());

    m_combatStatus.removeAttacker(attacker);
}

void Unit::removeAttacker(uint64_t guid)
{
    m_combatStatus.removeAttacker(guid);
}

void Unit::removeAttackTarget(Unit* attackTarget)
{
    ASSERT(attackTarget != nullptr);
    ASSERT(IsInWorld());

    m_combatStatus.removeAttackTarget(attackTarget);
}

void Unit::updateCombatStatus()
{
    m_combatStatus.update();
}

void Unit::clearAllCombatTargets()
{
    m_combatStatus.clearAllCombatTargets();
}

uint64_t Unit::getPrimaryAttackTarget() const
{
    return m_combatStatus.getPrimaryAttackTarget();
}
