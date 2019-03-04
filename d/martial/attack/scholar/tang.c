// Unknow sword, a sword gonfu for scholars.
inherit "/d/martial/attack/modify";
varargs int can_use(object me, object victim, object weapon)
{
	int type, lvl, i;
	string last;

	lvl = (int)me->query("scholar_gonfu/tang");
	if( undefinedp(lvl) ) return 0;
	if( last = (string)me->query_temp("last_attack_skill") )
		switch( last ) {
			case "tang1"  : type = 1;  break;
			case "tang2"  : type = 2;  break;
			case "tang3"  : type = 3;  break;
			case "tang4"  : type = 4;  break;
			case "tang5"  : type = 5;  break;
			default	        : type = 0;  break;
		}
	i = type * 15 + lvl * 2 + 1;
	if( type > 0 && type < 5 && random(i) > 15 * type ) type++;
	else type = 1;
	me->set_temp("last_attack_skill", ("tang"+type));
	return type;
}

int query_need_fp()
{
	return 3;
}

string *attack_msg = ({
"�����������Ե�Ʈ���Ժ�������ʫ������һ��֮���º躣�������غ᲻�ҹˡ������ϵ�%s৵�һ����%s��ȥ",
"�Ŀ������������·��ǹ������������ϸ衹���������˸�������������%s��%sֱ�̹�ȥ",
"��%sʹ����ʫ����֮�������̿����������΢�䡹�������������%s���˹�ȥ",
"���һ�������У�ʹ���������մ��졢��������������%s�����ƿ�֮����%s��ȥ",
"����%s������ƬƬ������ʹ���������ž��硢��ɽ�����Ρ����籩������%s��������"
});

int *hits = ({ 30, 55, 45, 65, 40 });
int *pens = ({ 15, 27, 35, 45, 50 });
int *dams = ({ 5, 7, 9, 11, 13 });

varargs int hit_modify(int hit, object me, object victim, object weapon, int type)
{
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -20;
	return ((hits[type-1] + random((int)me->query("scholar_gonfu/tang"))/6)*scholar_modify(victim)/100);
}

varargs int penetrate_modify(int pene, object me, object victim, object weapon, int type)
{
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -20;
	return ((pens[type-1] + random((int)me->query("scholar_gonfu/tang"))/6)*scholar_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        int lvl;

	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
        if (!weapon) return 0;
	me->add("force_points", -query_need_fp());
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/tang", 3*type+random(3*type));
        lvl = (int)me->query("scholar_gonfu/tang");
	return ((dams[type-1]+lvl/3)*scholar_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( type < 1 || type > 5 ) return 0;
	return attack_msg[(type-1)];
}
