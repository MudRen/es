// Unknow sword, a sword gonfu for scholars.
inherit "/d/martial/attack/modify";

varargs int can_use(object me, object victim, object weapon)
{
	int type, lvl, i;
	string last;

	lvl = (int)me->query("scholar_gonfu/song");
	if( undefinedp(lvl) ) return 0;
	if( last = (string)me->query_temp("last_attack_skill") )
		switch( last ) {
			case "song1"  : type = 1;  break;
			case "song2"  : type = 2;  break;
			case "song3"  : type = 3;  break;
			case "song4"  : type = 4;  break;
			case "song5"  : type = 5;  break;
			default	        : type = 0;  break;
		}
	i = type * 15 + lvl * 2 + 1;
	if( type > 0 && type < 5 && random(i) > 15 * type ) type++;
	else type = 1;
	me->set_temp("last_attack_skill", ("song"+type));
	return type;
}

int query_need_fp()
{
	return 2;
}

string *attack_msg = ({
"��¶����״��ʹ���δʽ���֮��ǧ��·أ��޴�����������%s��������%s",
"���������������Ū��Ӱ���������˼䡹�������е�%s�������������%s��ȥ",
"���΢Ц����%s������㽣��ʩչ�δʽ���֮����ѻ��㣬��ˮ�ƺ�ǽ����%s��ȥ",
"��̾һ����%s����бб����%s��ȥ��������紵�������ʹ������������������¡�",
"ʹ���δʽ�������ǿ�ġ�������Ƴ����磬���������ޡ���������%s��һ�Ž�ɫ��������%s��ȥ"
});

int *hits = ({ 30, 55, 45, 65, 40 });
int *pens = ({ 15, 27, 35, 45, 50 });
int *dams = ({ 1, 2, 3, 4, 5 });

varargs int hit_modify(int hit, object me, object victim, object weapon, int type)
{
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -20;
	return ((hits[type-1] + random((int)me->query("scholar_gonfu/song"))/6)*scholar_modify(victim)/100);
}

varargs int penetrate_modify(int pene, object me, object victim, object weapon, int type)
{
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -20;
	return ((pens[type-1] + random((int)me->query("scholar_gonfu/song"))/6)*scholar_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        int lvl;

	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
        if (!weapon) return 0;
	me->add("force_points", -query_need_fp());
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/song", 4*type+random(4*type));
        lvl = (int)me->query("scholar_gonfu/song");
	return ((dams[type-1]+lvl/3)*scholar_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( type < 1 || type > 5 ) return 0;
	return attack_msg[(type-1)];
}
