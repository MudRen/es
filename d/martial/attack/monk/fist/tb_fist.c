// �������书������ͨ��ȭ�� 
// modify by angel 
// 6/1 1994
inherit "/d/martial/attack/modify";
varargs int can_use(object me, object victim, object weapon)
{
        if( weapon ) return 0; // ͽ���书
        return 1;
}

// ��ʽս��ѶϢ
string *attack_msg = ({
        "%sʹ������ɳ���ơ�˫�ֿ�����%s�ӳ�",
        "%sʹ��һ�С����ɵ�ɽ��������%s",
        "%sƽ��һ�������ŷ��ڡ�������%s",
        "%s��������Ϯ��%s�����ˡ�����������",
        "%s˫�ֿ칥��ʹ��һ�С�˫������������%s",
        "%sһ�С�ִӡ���졻������%s",
        "%s����б���Ʒ��죬һ�С��������������%s",
        "%sһ����Х��ʹ����׷��������������%s",
        "%sʹ�������ӷ�������������%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
        return (25*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
        return (18*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        return ((random(6)+4)*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim,int type)
{
        if( !type ) return 0;
        return attack_msg[random(9)];
}
