// 少林寺武功「慈航普渡神功」

int query_need_fp()
{ 
    return 3;
}

varargs int can_use(object me, object victim, object weapon)
{
	if( undefinedp(me->query("monk_gonfu/chu-han")) ) return 0;
	return 1;
}

// 各式战斗讯息
string *defense_msg = ({
        "%s快速的连退三步",
        "%s使出『心念不起』，运功\护身", 
        "%s双掌合十，口颂『外离相为禅，内不乱为定』",
        "%s身体顺势一偏",
        "%s双手举起於头，身形忽然一乱",
        "%s口颂『动静无心，应用无碍』，运起内功\护身",
        "%s左手一架，身体向右一闪",
        "%s双手前举，默颂神功\口诀『心不住法，道即流通』",
});

varargs int hit_modify(int hit, object me, object victim, object weapon)
{
	int lvl;

   	if( (int)me->query("force_points") < query_need_fp() ) return -20;
   	lvl = (int)me->query("monk_gonfu/chu-han");
        me->add("gonfus_exp/chu-han", lvl+5);
        me->add("force_points", -query_need_fp() ); 
   	lvl = 20 + lvl/5+ random(lvl/3); 
   	return ((hit/3) > lvl ? lvl : hit/3 );
}

varargs int penetrate_modify(int pen, object me, object victim, object weapon)
{
   	return 0;
}

varargs int damage_modify(int damage, object me, object victim, object weapon)
{
	int lvl;

   	if( (int)me->query("force_points") < query_need_fp() ) return -5;
   	lvl = (int)me->query("monk_gonfu/chu-han");
   	lvl = 5 + random(lvl/3) ;
   	return ((damage/3) > lvl ? lvl : damage/3 );
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return defense_msg[random(8)]+"但运功\时显得内力不足";
        return defense_msg[random(8)];
}
