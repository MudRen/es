// godken.c
// This is a attack skill that is only available for wizards.

int query_need_fp()
{
	return 0;
}

varargs int can_use(object me, object victim, object weapon)
{
	if( weapon ) return 0;
	return 1;
}

string *attack_msg = ({
	"%s一掌拍向%s",
	"%s欺身前进，左掌成虎爪，直取%s",
	"%s身形一晃，右掌往%s一击",
	"%s纵身一跃，一记连环鸳鸯腿往%s连踢三下",
	"%s左掌右拳，一齐攻向%s",
	"%s左拳虚晃一招，右掌趁机打向%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon, int type)
{
	if( !type ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -50;
	return 100;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
	if( !type ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -50;
	return 100;
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
	if( !type ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
	return 100;
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( !type ) return 0;
	return attack_msg[random(sizeof(attack_msg))];
}
