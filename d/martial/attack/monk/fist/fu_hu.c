// �������书������ȭ�� 
// modify by angel 
// 6/1 1994
inherit "/d/martial/attack/modify";
int query_need_fp()
{
         return 2;
}

varargs int can_use(object me, object victim, object weapon)
{
        if( weapon ) return 0; // ͽ���书
        return 1;
}

// ��ʽս��ѶϢ
string *attack_msg = ({
        "%s����춱�ʹ��������˫��ȭ��˫ȭ��%s�ӳ�",
        "%s��ת����ʹ��һ�С��ڻ������������ֿ���%s",
        "%s�����������ƣ�ͻȻ˫�ֳɻ�צ����%s",
        "%s���ο�ת��ͻȻ����%s��һ�С��Ƶ�ǽ��ʹ��",
        "%s����бƫ���ã��漴һ�С�С�����¡�������%s",
        "%s��ȭ�����������࣬һ�С��������򡻣�������˷�����%s",
        "%s������𣬡��ڻ���צ��������צ��ƿ����������������%s",
        "%sһ����Х��ʹ�����ͻ�����������������%s",
        "%s����һ�䣬�������ʹ�����ͻ���������һ����������%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
        if( (int)me->query("force_points")<query_need_fp() ) return -5;    
        return (40*monk_modify(victim)/100) ;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
        if( (int)me->query("force_points")< query_need_fp() ) return -5;
        return (30*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
        return ((11+random(7))*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim,int type)
{
        if( !(type) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(9)]+"���ǳ���ʱ�Ե���������";
        return attack_msg[random(9)];
}
