// wei-to.c
// This is a attack skill that is only available for monk.
inherit "/d/martial/attack/modify";
int query_need_fp()
{
       return 3;
}

varargs int can_use(object me, object victim, object weapon)
{
	if( weapon ) return 0;
	return 1;
}

string *attack_msg = ({
"%s『沧海桑田』『海枯\石烂』拍向%s",
"%s欺身向前，左掌劈出『空谷回音』，直取%s",
"%s身形一晃，右掌『无求乃乐』往%s一击",
"%s纵身一跃，一记『当头棒喝』往%s连劈三下",
"%s左掌右拳，『回头是岸』攻向%s",
"%s左拳虚晃，右掌趁机打出『雨过天晴』向%s",
"%s凝神使出『悬崖勒马』右手向%s挥出",
"%s左手护额，右手强袭%s，一招『连环绝手』打出",
"%s右手如狂风暴雨，一招『逆浪强袭』，砍向%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon, int type)
{
        if ( (int)me->query("force_points") < query_need_fp() ) return -10;
	return (54*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
        if ( (int)me->query("force_points") < query_need_fp() ) return -10;
	return (32*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon,int type)
{
        if ( (int)me->query("force_points") < query_need_fp() ) return -10;
	me->add("force_points", -query_need_fp());
        return ((13+random(8))*monk_modify(victim)/100); 
}

varargs string query_attack_msg(object me, object victim, int type)
{
        if( !(type) ) return 0;
        if( (int)me->query("force_points") < query_need_fp() )
        return attack_msg[random(9)]+"但是出手时显得内力不足";
        return attack_msg[random(9)];
} 
