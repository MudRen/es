//#pragma save_binary

#include <mudlib.h>

#define MONK_GONFU_DIR "/d/monk/gonfus/"

inherit DAEMON;

int help();

int cmd_eungon(string str)
{
        string *fist = ({ "sh_fist", "tb_fist", "long_fist", "ro_han",
                "drunk_fist", "fu_hu", "wei_to", "ho_fist" });
        string *heals = ({ "bi-du", "gun-in", "lun-chi", "pu-ty", });
        string *cures = ({ "bi-du",  "lun-chi",  });
        string *gonfus = ({ "bolo-mi", "chu-han", "fu-mo", "gi-mei", "tai-zuo",
                "wu-sur", "body-def", "bolo-fist", "dragon-claw", "keep-flower",
                "da-mo","power-finger","ru-lai","king-kong", "burn-blade","fon-mo",
                "god"});
        int level, heal;
        object code, me;

        if( !str ) return help();

        me = this_player();
        if( (int)me->query("stop_attack")>0 )
                return notify_fail ("( 你上一个动作还没有完成，无法施展招式。 )\n");
        if( me->query_temp("stop_eungon") || me->query("stop_eungon") )
                        return notify_fail("你正准备使用招式时，竟然发现你突然功\力全失了。\n");

        if( member_array(str, fist) != -1 )
                return notify_fail("基础拳法可用 fist 指令使用, 不须运功\。\n");

        if( member_array(str, heals) != -1 ) heal = 1;
        else if( member_array(str, gonfus) != -1 ) heal = 0;
        else return notify_fail("疑! 这是那一种功夫?\n");

        if( (heal && member_array(str, me->query("monk_gonfu/heal"))==-1) ||
                (!heal && undefinedp(level=(int)me->query("monk_gonfu/"+str))) )
                return notify_fail("疑! 你会这种功夫?\n");

        if ( (!heal) && 
             ( me->query("gonfu_busy") || me->query_temp("gonfu_busy") )  
           )
        if ( !me->query_temp("gonfu_top") )
        return notify_fail("你目前正运功所以无法另外运用其它武功\。\n");
        code = find_object_or_load(MONK_GONFU_DIR+(heal?"heal/":"general/")+str);
        if( !code )
                return notify_fail("没有这种功夫! 请通知巫师或用 bug 指令报告招式名称。\n");
        if( me->query_temp("gonfu_top") ) {
           me->delete("attack_skill");
           me->delete("defense_skill");
           }
        code->eungon(me, level);
        return 1;
}

int help()
{
                write( @C_HELP
指令格式: eungon <招式名称>

这个指令让你用来施展招式。你可以用 gonfus 指令看你目前已经学会的招式列表。
C_HELP
                );
    return 1;
}
