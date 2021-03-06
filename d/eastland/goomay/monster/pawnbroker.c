
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(10);
        set_name( "Pawnbroker", "刘朝奉" );
        add ("id",({ "liu"}));
        set_short( "刘朝奉");
        set("unit","位");
        set_long(
@C_LONG
    他是一个戴著一只玻璃镜片的老朝奉，一身蓝天长袍加上瓜皮小帽，
一看就觉得他是个十分谨慎的人，别看他老，他可是京城最有名的三大
朝奉之一，商业界响当当的第一买卖高手，这次是专门受钱不多重金礼
聘来管理他在古梅镇的各家行号的。或许\你可以向他请教有关於商店的
种种。
C_LONG
);
        set ("gender", "male");
        set ("race", "human");
	set( "alignment",300);
        set_natural_armor( 50, 20 );
        set_natural_weapon( -10, 1, 3 );
        set_perm_stat( "str", 15 );
        set_perm_stat( "kar", 12 );
        set_perm_stat( "int", 20 );
        set_perm_stat( "dex", 15 );
        set_skill( "blunt", 80 );
        set_skill( "parry", 60 );
        set( "hit_points", 280 );
        set( "max_hp", 280 );
        set( "special_defense", ([ "all": 20 ]) );
	set("wealth/gold",20);
        wield_weapon( Obj"abacus" );
        equip_armor( Obj"long_garb" );
        equip_armor( Obj"round_cap" );
        equip_armor( Obj"emerald_ring" );
        set( "inquiry", ([
		"statue"  : "@@ask_statue",
        ]) );

}

int ask_statue()
{
        object me ;
        me=this_player();
       if ((int)this_player()->query_quest_level("Goddess_statue")>2 ) {
                tell_object(me,
                "刘掌柜笑道：「月神像已经找回来了，多谢您的帮忙 !!」\n");
                return 1;
	}
        else
        {
	tell_object(me,@C_STATUE
刘掌柜叹道：「那月神像是月神教的精神象徵，据说隐藏有强大的力量，一向
为该教的镇教之宝，半个月前我回京城办事，回到店里，伙计们居然收了这麽
一个烫手山芋，结果当天晚上就有人夜闯库房，单单只偷走了这尊神像，吓得
我六神无主，果然几天以後，月神教的人纷纷找到我头上，威胁利诱、要杀要
剐的，可是我哪里有办法？後来听说那贼被抓了，我赶紧到衙门疏通，结果也
没有神像的下落，最後那贼居然越狱了 ... 我 ... 我乾脆死了算了」
C_STATUE
	);
                return 1;
	}
}

int accept_item(object me,object item)
{
     if ( ((string) item->query("name") !="The statue of Goddess" &&
	 (string) item->query("name") !="broken symbol") ||
       (int)this_player()->query_quest_level("Goddess_statue")>2 ) {

     tell_object(me,
        "刘掌柜道：「谢谢 !! 但是我是个诚实的生意人，不能乱收你的东西。 」\n");
	command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
	}

	if ( (string)item->query("name") == "broken symbol" ) {
     tell_object(me,@SYMBOL
刘掌柜道：嗯 !! 这东西看起来似乎很不平凡，你何不请高手匠人帮你修修。 
或许\能恢复旧观也说不定，剑卢主人段铁应该有这份功\力吧 !!
SYMBOL
		 );
        command("give "+(string)item->query("name")+" to "+lower_case((string)me->query("name")));
        return 1;
	}
     tell_object(me,
@MISSION
刘掌柜把月神像翻来覆去的看了一遍：「这 .. 这是真的月神像 !! 谢谢你 !! 我有
救了 !! 我有救了 !! 」他高高兴兴的把女神像秘密的收藏起来，打开库房，准备恢
复营业。

MISSION
);
	if (item->query("who_get_me") == this_player()->query("name")) {
	tell_object(me,
	"你终於完成了寻找月神像的任务 !! "+set_color("[ 你得到 15000 点经验 ]","HIC")+"\n" );
	me->finish_quest("Goddess_statue",3);
        me->gain_experience(15000);
	}

        item->remove();

        return 1;
}
