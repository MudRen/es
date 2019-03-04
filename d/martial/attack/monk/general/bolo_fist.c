inherit "/d/martial/attack/modify";
void special_attack(object ob1, object victim)
{

  if ( !ob1->query_attackers() || !victim ) {
		return ;
	}
tell_object( victim, 
 (string)ob1->query("c_name")+"ʹ���������ơ��İ���������һ���������������������Ѫ��\n\n");

tell_room( environment(ob1), 
 "\n\n"+(string)ob1->query("c_name")+"ͻȻ��Хһ�����ĳ�һ���ۻ��������" + (string)victim->query("c_name") + "��ÿ�����Ѫ��\n",
({ victim, ob1 }) );

write( 
"\n\n�㳤Хһ�����û����������Ƶľ��У�ǿ���������" + (string)victim->query("c_name") +"�����Ѫ���磡\n\n" );

victim->receive_damage( 5+(int)ob1->query("monk_gonfu/bolo-fist") );

    if( wizardp(ob1) )
       printf("\n[ Receive_damage : %d ]\n",5+(int)ob1->query("monk_gonfu/bolo-fist"));
}


int query_need_fp()
{ 
    return 5;
}

varargs int can_use(object me, object victim, object weapon)
{
	int type, i, lvl;
	string last;

	if( weapon || undefinedp(lvl=(int)me->query("monk_gonfu/bolo-fist")) )
		return 0;
	if( last = (string)me->query_temp("last_attack_skill") )
		switch( last ) {
			case "bolo-fist1"  : type = 1;  break;
			case "bolo-fist2"  : type = 2;  break;
			case "bolo-fist3"  : type = 3;  break;
			case "bolo-fist4"  : type = 4;  break;
			case "bolo-fist5"  : type = 5;  break;
			case "bolo-fist6"  : type = 6;  break;
		 	case "bolo-fist7"  : type = 7;  break;
			case "bolo-fist8"  : type = 8;  break;
			default            : type = 0;  break;
		}
	i = type * 10 + lvl * 4 + 1;
	if( type > 0 && type < 8 && random(i) > type * 10 ) type++;
	else type = 1;
	me->set_temp("last_attack_skill", ("bolo-fist"+type));
	return type;
}

string *attack_msg = ({
		"%s�������ƣ�ʹ������%s", 
		"%sһ�С����Ǵ��¡�����%s",
		"%s����ǰ�ۣ�������������%s",
		"%s˫�ƺ϶���£��һ�ɼ�ǿ��������%s�����ǡ�Ͽ����硻",
		"%s������΢��ʵ�������������飬һ�С������޷졻����%s",   
		"%s�����ĳ�һ�ơ������������ƻֺ꣬����%s",
		"%s���һ����һ�ǡ���Բ���𡻴���ھ�����%s",
		"%s����������ʹ����ǿһʽ��������ӿ��˫�������������%s",
});

int *hits = ({  70, 72, 96, 122, 92, 100,  90, 134 });
int *pens = ({  48, 88, 60, 110, 70,  78,  94, 120 });
int *dams = ({  27, 34, 35, 44, 40, 45, 55, 62 });
// ����:        1  .9  .75 .58 .41 .27 .17 .10   type*10+lvl(max 25)*4 
// ����ֵ:      27  30  32  34  36  37  39  41  

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
	return ((pens[type-1] + (int)me->query("monk_gonfu/bolo-fist")/4)*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon,int type)
{
        int lv;
        lv = me->query("monk_gonfu/bolo-fist");
	if( type < 1 || type > 8 ) return 0;
   	if( (int)me->query("force_points") < query_need_fp() ) return -5;
   	me->add("force_points", -query_need_fp());
        if (!environment(me)->query("PK_ZONE"))
   	me->add("gonfus_exp/bolo-fist", 3*type+1+random(2*type));
        if (random(350)<lv) special_attack(me,victim); 
	return (dams[type-1]*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( type < 1 || type > 8 ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[type-1]+"���ǳ���ʱ�Ե���������"; 
	return attack_msg[type-1];
}
