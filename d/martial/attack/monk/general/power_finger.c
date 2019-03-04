inherit "/d/martial/attack/modify";

int query_need_fp()
{ 
    return 5;
}

varargs int can_use(object me, object victim, object weapon)
{
	int type, i, lvl;
	string last;

	if( weapon || undefinedp(lvl=(int)me->query("monk_gonfu/power-finger")) )
		return 0;
	if( last = (string)me->query_temp("last_attack_skill") )
		switch( last ) {
			case "power-finger1"  : type = 1;  break;
			case "power-finger2"  : type = 2;  break;
			case "power-finger3"  : type = 3;  break;
			case "power-finger4"  : type = 4;  break;
			case "power-finger5"  : type = 5;  break;
			case "power-finger6"  : type = 6;  break;
			case "power-finger7"  : type = 7;  break;
			case "power-finger8"  : type = 8;  break;
			default            : type = 0;  break;
		}
	i = type * 10 + lvl * 4 + 1;
	if( type > 0 && type < 8 && random(i) > type * 15 ) type++;
	else type = 1;
	me->set_temp("last_attack_skill", ("power-finger"+type));
	return type;
}

string *attack_msg = ({
		"%s����ָ�⣬һָ��%s��ȥ", 
		"%s��������һ�ǡ����᳤�硻��������%s",
		"%s����һ�ƣ�����һ�С���շ�����������%s",
		"%s���ص�����֡��ɺ��������ƻֺ꣬����%s",
		"%s̤���ҽţ�˫ָ���϶��¹�����һ�С���ָ���������ٹ���%s",   
		"%s˫ĿԲ����һ��ǿ��ָ��ӿ��%s�����ǡ����ŭĿ��",
		"%s������һ�����������������졻����ھ�����%s",
		"%s����ȫ��ʹ���ռ�һʽ�������ħ��һ����ھ���ӿ����%s",
});


int *hits = ({  75, 80, 96, 132, 92, 104,  95, 154 });
int *pens = ({  49, 88, 60, 115, 80,  85,  98, 130 });
int *dams = ({  27, 33, 34, 43, 40, 44, 50, 63 });
// ����:        1  .9  .75 .58 .41 .27 .17 .10   type*10+lvl(max 25)*4 

varargs int hit_modify(int hit, object me, object victim, object weapon,int type)
{
	if( type < 1 || type > 8 ) return 0;
   	if( (int)me->query("force_points") < query_need_fp() ) return -10;
	return (hits[type-1]*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pene, object me, object victim, object weapon,int type)
{
	if( type < 1 || type > 8 ) return 0;
   	if( (int)me->query("force_points") < query_need_fp() ) return -10;
	return ((pens[type-1] + random((int)me->query("monk_gonfu/power-finger")/2))*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon,int type)
{
        int lv;
        lv = me->query("monk_gonfu/power-finger");
	if( type < 1 || type > 8 ) return 0;
   	if( (int)me->query("force_points") < query_need_fp() ) return -5;
   	me->add("force_points", -query_need_fp());
        if (!environment(me)->query("PK_ZONE"))
   	me->add("gonfus_exp/power-finger", 3*type+1+random(2 * type));
        if (random(350)<lv) { 
           me->add("force_points", query_need_fp());
           this_player() -> continue_attack();   
           tell_object( me, set_color("�㳤Хһ�������ָ�������״ν���! \n","HIR") ); 
        if (random(180)<lv) { 
           me->add("force_points", query_need_fp());
           this_player() -> continue_attack();   
           tell_object( me, set_color("�㳤Хһ�������ָ�������ٴν���! \n","HIR") );  
                            }  
                            }
	return (dams[type-1]*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( type < 1 || type > 8 ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[type-1]+"Ω����ʱ�Ե���������"; 
	return attack_msg[type-1];
}
