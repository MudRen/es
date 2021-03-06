// 少林寺武功「伏魔棍法」
inherit "/d/martial/attack/modify";

int query_need_fp()
{ 
    return 2;
}

varargs int can_use(object me, object victim, object weapon)
{
        if( !weapon || !((string)weapon->query("type") == "blunt"
                    ||   (string)weapon->query("type") == "bo" ) )
                    return 0;
	return 1;
}

string *attack_msg = ({
        "踏上一步，%s向%s直劈下来，劲势十分强劲",
        "使出伏魔棍法中一招『诸恶莫做』，%s自左而右，横扫%s",
        "%s一连三棍，卷起飞沙走石，扑向%s",
        "左手握拳，右手的%s卷著一阵劲风，攻向%s",
        "双腿右转寒鸡步，%s使出一招『一夫当关』，劈向%s",
        "%s如万钧雷霆，连续攻出『龙飞凤舞』、『风狂雨骤』二式，击向%s",
        "身形向右方一闪，%s不退反进，快速无比的刺向%s",
        "大喝一声，%s使出伏魔棍法的『如影随形』，击向%s",
        "将%s快速旋转，但见满天棍影，突然一招『力挽狂澜』，出其不意的攻向%s",
});

varargs int hit_modify(int hit, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/fu-mo");
	lvl = 10 + lvl/2 + random(lvl/4);
	return (( ((hit/4)>lvl) ? lvl : hit/4 )*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	lvl = (int)me->query("monk_gonfu/fu-mo");
	lvl = 10 + random(lvl);
	return  (lvl*monk_modify(victim)/100);
}

varargs int damage_modify(int dam, object me, object victim, object weapon,int type)
{
	int lvl;

	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
	lvl = (int)me->query("monk_gonfu/fu-mo");
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/fu-mo", lvl/2+3);
	return (4*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( !type ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(9)]+"但是出手时显得内力不足";
        return attack_msg[random(9)];
}
