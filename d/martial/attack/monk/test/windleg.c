// �������书����צ�֡� part2
// Text Data from book �����������ǡ�
// modify by Wind
// May 28 1994
// second modify by Wind
// Jun 4 1994

int query_need_fp()

{ 
    return 5;
}
int gonfu_level(object me)
{
        // ��������ֵ
        return (int)me->query("gonfus/windleg");
        //                     ^^^^^^^^^^^^^^^^^^������
}

varargs int can_use(object me, object victim, object weapon)
{
        // ȷ����ʹ�������Ƿ���ȷ
        if( weapon ) return 0; // ͽ���书
        return 1;
}

// ��ʽս��ѶϢ
string *attack_msg = ({
        "%s�������������%s",
        "%s����һ���������ߵ���%s",
        "%sʹ��������¥��һ�У������߳����ߵ�%s",
        "%s����һ�䣬�����������",
        "%sͻȻ�����˶�����ǰ������%s",
        "%s������𣬴Ӹߴ�����%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
	int i,delta_dex;
        // �����ʵ���
        if( !(type) ) return 0;
        delta_dex = (int)me->query_stat("dex")-(int)victim->quert_stat("dex");
        if ( delta_dex<0) { delta_dex=0; } 
        // �����ʵ���ֵΪ �ٷ�֮�� 30 + ������/3 + ˫�����ݶȲ�/2 ��
        i = 30 + gonfu_level(me)/20 + delta_dex*5 ;
   	if( (int)me->query("force_points") < query_need_fp() ){	i = -5; }
        return i;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon,int type)
{
        // ��͸�ʵ������ٷ�֮ʮ���ٶȿ죬��͸�ʾ�С�ˣ�
        return -10;
}

varargs int damage_modify(int damage, object me, object victim, object weapon,int type)
{
        int i;
        // ����������
        if( !type ) return 0;
        i = gonfu_level(me)/5+10;
        // ����������Ϊ�ٷ�֮��  ������/5+20��
        if( (int)me->query("force_points") < query_need_fp() ){	i = -5; }
            else {me->add("force_points",-query_need_fp()); } 
        return i;
}

varargs string query_attack_msg(object me, object victim, int type)
{
        string a_msg;
        if( !(type) ) return 0;
        a_msg = attack_msg[random(sizeof(attack_msg))];
        if( (int)me->query("force_points") < query_need_fp() )
        { a_msg = a_msg+"�����ǳ���ʱ�Ե���������ĸо�";}
return a_msg;
}
