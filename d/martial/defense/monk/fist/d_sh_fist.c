// �������书��С��ȭ�� part3
// angel
// Jun 4 1994


varargs int can_use(object me, object victim, object weapon)
{
        if (weapon) return 0;
        return 1;
}

string *defense_msg = ({
        "%s����һ��",
        "%s����һ��", 
        "%s˫�ƻ���",
        "%s����˳��һƫ",
        "%s���ֻ�ͷ������һ��",
        "%s���ֺ��",
        "%s˫��ǰ�٣�΢һ��ת����",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon )
{
        return 5;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon)
{
        return 0;
}

varargs int damage_modify(int damage, object me, object victim, object weapon)
{
        return 0;
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim, weapon) ) return 0;
        return defense_msg[random(7)];
}
