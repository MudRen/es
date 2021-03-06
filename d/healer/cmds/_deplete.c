//	_deplete.c	放血解毒术
//
//		Lilia
	////#pragma save_binary
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit DAEMON;

int cmd_deplete(string arg)
{
    object dest, weapon;
    int skill, skill2;
    mixed poisoned;

    if (!arg || arg == "" || !(dest = present(arg, environment(this_player()))))
  	return notify_fail("你想替谁解毒? \n");
    
    if (!living(dest)) return notify_fail("这个「东西」会中毒吗? \n");

    if (dest->query("npc")) return notify_fail("你不能替 NPC 放血。\n");

    if (dest->query("ghost")) return notify_fail("要上大体解剖到医学院去，不要拿死□开玩笑！\n");
    
    weapon = this_player()->query("weapon1");
    if ((!weapon) || (string)weapon->query("type") != "dagger")
	return notify_fail("你没有装备适当的工具，没办法放血。\n");

    if (this_player()->query("stop_attack") != 0)
        return notify_fail("你的上个动作还没有完成，没办法替人放血。\n");

    if (!(poisoned = dest->query("conditions/simple_poison")))
        return notify_fail("想 PK 直接打 kill <某人> 就可以了，不必放血。\n");

    if (dest->query_temp("depleted"))
	return notify_fail("患者刚放过血，不能立刻再行放血。\n");
    
    if ((int)dest->query("hit_points") <= 20)
	return notify_fail("患者已经奄奄一息了，恐怕经不起放血的治疗。\n");

    skill = (int)this_player()->query_skill("clotting");
    if (!skill) return notify_fail("没学过止血就想放血? 不好吧 ....\n");

    skill2 = (int)this_player()->query_skill("anatomlogy");
    if (!skill2) return notify_fail("没学过解剖学就想放血? 回去练个十年再来吧!\n");

    write("你替" + dest->query("c_name") + "进行放血 ....\n");
    tell_object(dest, this_player()->query("c_name") + "替你进行放血 ... 你觉得好多了!\n");
    tell_room(environment(this_player()), this_player()->query("c_name") + "替" + dest->query("c_name") + "进行放血。\n", ({this_player(), dest}));
   
    if (dest != this_player()) this_player()->add("alignment", 25);

    if (skill2/2 + random(skill2/2) > poisoned[1] * poisoned[2])
    {
	this_player()->receive_experience(skill2);
	(CONDITION_PREFIX + "simple_poison")->remove_effect(dest);
    }
    else
    {
	poisoned[2] /= 2;
	dest->set("conditions/simple_poison", poisoned);
	this_player()->receive_experience(skill2 / 2);
    }

    dest->set_temp("depleted", 1);
    dest->receive_damage(20 - random(skill/5)); 
    call_out("remove_depleted", 120, dest);
    return 1;
}

void remove_depleted(object player)
{
    if (player) player->set_temp("depleted", 0);
}

int help()
{
    write(
    @C_HELP
指令格式： deplete <某人>

这个指令让你替某个人物放血解毒，放血的结果可能是完全解去毒性，
或是将毒性减半。但不论是否完全成功，患者的体力都有可能会下降，
这与施术者的止血技能有关。放过血的人大约在两分钟内不能再度放血
解毒，以免血液流失过多。
C_HELP
    );
    return 1;
}

