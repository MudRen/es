
inherit "/d/martial/attack/modify";

varargs int can_use(object me, object victim, object weapon)
{
	int type, lvl, i;
	string last, spouse_name, name2;
        object spouse, env;
        

	lvl = (int)me->query("scholar_gonfu/couples_sword");
	if( undefinedp(lvl) ) return 0;
        spouse_name = me->query("spouse");
        
        if (!spouse_name) {
          tell_object(me,"������޷��˽����׽����ľ���ġ�\n");
          return 0;
        }
        
        env = environment(me);
        spouse_name = lower_case(spouse_name);
        spouse = find_living(spouse_name);
        if ( !spouse || !present(spouse,env) ) {
          tell_object(me,"��Ϊȱ������һ��ĸ������޷�ʩչ���׽�����\n");
          return 0;
	}
	/* ������ʹ��ʱԤ������ */
        name2=lower_case(spouse->query("spouse")); 
        if (name2!=me->query("name")){
          tell_object(me,"��Ȼ������ͬ, ���ǶԷ�ȴ���������ż��\n");
          return 0;         
        }
	if (spouse->query("attack_skill")!="scholar/couples_sword"){
          tell_object(me,"��Ϊȱ��Э����ʹ���޷�ʩչ���׽�����\n");
 	  return 0;
	}
        if (!spouse->query_attackers())
          spouse->kill_ob(victim);   

	if( last = (string)me->query_temp("last_attack_skill") )
		switch( last ) {
			case "couples_sword1"  : type = 1;  break;
			case "couples_sword2"  : type = 2;  break;
			case "couples_sword3"  : type = 3;  break;
			case "couples_sword4"  : type = 4;  break;
			case "couples_sword5"  : type = 5;  break;
			default	     : type = 0;  break;
		}
	i = type * 15 + lvl * 2 + 1;
	if( type > 0 && type < 5 && random(i) > 15 * type ) type++;
	else type = 1;
	
        /* for some special case only */
        if (!me->query_temp("c_spouse"))
          me->set_temp("c_spouse",spouse->query("c_name"));  
	me->set_temp("extra_db/couples_sword", 3 + lvl/5);
	me->set_temp("last_attack_skill", ("couples_sword"+(string)type));
	return type;
}

int query_need_fp()
{
	return 4;
}

string *msg_one = ({
"����%s����",
"�ĳ���һ�죬����ɱ��%s",
"����%s�������ɻ�����ס���˵Ĺ��ƣ�",
"�û�����%s",
"һ��%s������ӯ�������",
"��������佣������%s",
"һʽ����Ͷ��ϡ����˽���ɣ������",
"��һ��һ�ҹ���%s",
"��ʽ��Ъ����",
"������������%s�������ӳ�Ի��һ�����������죬������������ס%s",
"����΢��������%s�����������ϡ�һ�������������������ᣬ��",
"һǰһ��й�%s"
});

string *msg_two = ({
"����һ�䣬һ��%s���������಻��������ͬ�޾���Ũ������һ�㹥��%s",
"��%s�˽���һ��Ю�����콣������%s"
});

string *msg_three = ({
"������磬������ʽ������˫�ɡ�����ʽ���߲�����%s���������%s",
"һ�����������������ּ��������һ�С���ʷ��������%s�ڿ��лó�һ�����ֱ��%s",
"��ִ%s���Ų����ǣ���ת���У�ʹ��һ�С�С�ǳ��ޡ������������˵Ĺ�������϶�ݳ�һ������%s",
"�ֳ�%s����б����һʽ��Ū�����ֻ��������������ɫ������ת��Ϣ����%s��ȥ"
});

int *hits = ({ 35, 40, 45, 50, 55 });
int *pens = ({ 15, 27, 35, 45, 50 });
int *dams = ({ 10, 14, 18, 22, 25 });

varargs int hit_modify(int hit, object me, object victim, object weapon, int type)
{
  if( type < 1 || type > 5 ) return 0;
  if( (int)me->query("force_points") < query_need_fp() ) return -20;
  return ((hits[type-1]+random((int)me->query("scholar_gonfu/couples_sword"))/6)*scholar_modify(victim)/100);
}

varargs int penetrate_modify(int pene, object me, object victim, object weapon, int type)
{
    if( type < 1 || type > 5 ) return 0;
    if( (int)me->query("force_points") < query_need_fp() ) return -20;
    return ((pens[type-1]+random((int)me->query("scholar_gonfu/couples_sword"))/6)*scholar_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        int lvl;

	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
        if (!weapon) return 0;
	me->add("force_points", -query_need_fp());
	if (!environment(me)->query("PK_ZONE"))
	  me->add("gonfus_exp/couples_sword", 5*type+random(10));
        lvl = (int)me->query("scholar_gonfu/couples_sword");
	return ((dams[type-1]+lvl/3)*scholar_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
        string c_spouse;
        int type_ext;
        
	if( type < 1 || type > 5 ) return 0;
        type_ext = type*2 - (int)random(2);
        c_spouse = me->query_temp("c_spouse");
        switch (type) {
          case 1 : 
          case 2 :
          case 3 :
            return sprintf("%s%s%s",msg_one[(type_ext-1)*2],
                           c_spouse,msg_one[(type_ext-1)*2+1]);            
            break; 
          case 4 :
            return msg_two[(type_ext-7)];        
            break;
          case 5 :
            if (me->query_temp("enhant_seq")==1)
              return msg_three[(type_ext-9)];
            else
              return msg_three[(type_ext-9)];  
          default :
            return 0;
        }
}
