// �������书������С��ȭ�� 
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
        "%s����һ����%s�ӳ�",
        "%sʹ���������ޡ�������%s",
        "%s����������%s",
        "%s�ɹ�����������бץ%s��һ�С�����б�Ρ�����",
        "%sһ�С��鲽���ǡ�������%s",
        "%s���ҿ�����ץ��%s",
        "%s��ǰһ��������%s",
        "%s����һת��ʹ����ת�����ȡ�������%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
        return (20*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
        return (15*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        return ((random(5)+1)*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim,int type)
{
        if( !type ) return 0;
        return attack_msg[random(8)];
}
