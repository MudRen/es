// �������书����ȭ�� part3
// angel
// Jun 4 1994

varargs int can_use(object me, object victim, object weapon)
{
        if(weapon) return 0;
        return 1;
}

// ��ʽս��ѶϢ
string *defense_msg = ({
        "%sʹ����̫����ơ�����Ʈ��", 
        "%s���ƻ���˳������һ��",
        "%s���ֻ��ʹ����������ƺ��",
        "%s��������",
        "%s������ǰ��ס",
        "%sһ�С����ɰ��졻˳������һ��",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon )
{
        return 10;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon)
{
        return 4;
}

varargs int damage_modify(int damage, object me, object victim, object weapon)
{
        return 0;
}
varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim, weapon) ) return 0;
        return defense_msg[random(6)];
}
