// �������书������ȭ�� part3
// angel
// Jun 4 1994

varargs int can_use(object me, object victim, object weapon)
{
        if( weapon) return 0;
        return 1;
}
string *defense_msg = ({
        "%s˫��������ǰһ��", 
        "%sʹ�����ڻ���ɽ��˫�ƻ���",
        "%s�����³������ֻ���",
        "%sӲ�����ĳ��ܴ�һ����",
        "%s������ǰ����һ��",
        "%s��ת���Σ��ӳ�˫ȭһ��",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon )
{
        return 6;
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
