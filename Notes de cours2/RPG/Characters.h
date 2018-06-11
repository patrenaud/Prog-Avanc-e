#pragma once

struct Stats
{
	Stats(const int a_Damage, const int a_Hp)
		: m_AttackDamage(a_Damage)
		, m_Hp(a_Hp)
	{
	}

	int m_Hp;
	int m_AttackDamage;
};

class Characters
{
public:
	Characters(const int a_Damage, const int a_Hp);
	virtual ~Characters();

	void TakeDamage(const int a_Damage) {m_Stats->m_Hp -= a_Damage;}
	const int GetHp() { return m_Stats->m_Hp; }
	const int GetAttackDamage() { return m_Stats->m_AttackDamage; }

private:
	Stats* m_Stats;

};

