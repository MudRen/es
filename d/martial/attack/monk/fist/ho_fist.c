// �������书����ȭ�� 
// modify by angel 
// 6/1 1994
inherit "/d/martial/attack/modify";
int query_need_fp()
{
         return 1;
}

varargs int can_use(object me, object victim, object weapon)
{
        if( weapon ) return 0; // ͽ���书
        return 1;
}

// ��ʽս��ѶϢ
string *attack_msg = ({
        "%sʹ����Գ�������˫ȭ��%s��ץ",
        "%s��ת����ʹ��һ�С�С������б��ץ��%s",
        "%s˫����ɣ�������%sһץ",
        "%s���ο�ת��ͻȻ����һ�С�Գ����졻����%s",
        "%s����бƫ���漴һ�С�Գ����ɽ��������%s",
        "%sץץ������һ�С����תȦ��������%s",
        "%s�������𣬡����Ͼ�����Ѹ������%s",
        "%sһ����Ц��ʹ�������߽�צ������������%s",
        "%s����һ��ֱ�����̣�ʹ��������͵�ҡ���ץ��%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
        if( (int)me->query("force_points")<query_need_fp() ) return -5;    
        return (40*monk_modify(victim)/100);  
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
        if( (int)me->query("force_points")< query_need_fp() ) return -5;
        return (20*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{       
        if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
        return ((10+random(4))*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim,int type)
{
        if( !(type) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(9)]+"���ǳ���ʱ�Ե���������";
        return attack_msg[random(9)];
}
