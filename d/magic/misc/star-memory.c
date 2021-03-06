// This is a spell object. type -> misc
// level    0
// cost    50
// time    --
// skill   80
// G_LVL   --	注: 魔法熟练度对本法术无任何影响
// G_EXP   30
#include <mudlib.h>
#define TYPE "misc"

inherit DAEMON;
inherit "/d/magic/magic";
inherit MESSAGE;

int query_gain_spell_exp(int level) { return 30; }

int query_need_spell_level(int level) { return 0; }

int query_sp_cost(object caster, int level) { return 50; }

int query_need_skill(int level) { return 80; }

int cast(int level, string dest)
{
    object me;
	
	me = this_player();

	if( (int)me->query_skill("misc") < query_need_skill(level) ) {
	  tell_object( me, 
		      "你的杂项魔法技能不足以使用这个魔法! \n" 
		      );
      return 0;
    }

	if (!dest) {
		tell_object( me, "你想把关於这个地方的记忆寄放在哪里呢?\n" );
		return 0;
	}
	switch (dest)
	{
		case "aqua"		: break;
		case "pyro"		: break;
		case "aero"		: break;
		default	:	{
			tell_object(me, @FAIL
「星之忆」可以将所有关於此地的回忆寄放於天上的星辰, 但是仅有水之
星 (Aqua) 火之星 (Pyro) 与风之星 (Aero) 才拥有足够的能力存下如此
多的思绪。
指令格式: cast star-memory [on|at] <星辰>
FAIL
			);
			return 0;
		};
	}

	if ( !environment(me)->query("outside") )
	{
		tell_object( me, "这里看不到星星, 没办法使用星之忆。\n");
		return 0;
	}	
	if ( environment(me)->query("no_teleport") )
	{
		tell_object( me, "在这里无法感受到天上的诸星, 无法留下记忆。\n");
		return 0;
	}
	
	emote( "$NS低头默念咒文, 将所有关於此地的记忆系结於天上的诸星。\n"
		, me );

	me->set("teleport_points/" + dest, base_name(environment(me)) );
    gain_spell_experience(me, TYPE, query_gain_spell_exp(level));
	return 1;
}
