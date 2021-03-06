//#pragma save_binary
// _brood.c
// This command is for spell users to quiet down and concentrate on recover
// spell points.
// by Annihilator@Eastern.Stories (12-17-93)
// modified by Oldcat@Eastern.Stories (1-18-95)
#include <mudlib.h>

inherit DAEMON;
string *c_illusion = ({
        "神将八卦分八节，一气统三为正宗。\n",
        "阴阳二遁分顺逆，一气三元人莫测。\n",
        "五日都来换一元，接气超神为准的。\n",
        "认取九宫为九星，八门又遂九星行。\n",
        "九宫逢甲为直符，八门直使自分明。\n",
        "符上之门为直使，十时一位堪凭据。\n",
        "直符常遣加时干，直使逆顺遁宫去。\n",
        "六甲元号六仪名，三奇即是乙丙丁。\n",
        "阳遁顺仪奇逆布，阴遁逆仪奇顺行。\n",
        "吉门偶尔合三奇，直此虽云百事宜。\n",
        "更合从傍加简点，馀宫不可有微疵。\n",
        "三奇得使诚堪取，六甲遇之非小补。\n",
        "乙逢犬马丙鼠猴，六丁玉女骑龙虎。\n",
        "又有三奇游六仪，号为玉女守门扉。\n",
        "若作阴私和合事，请君但向此中推。\n",
        "天三门兮四地户，问君此法如何处。\n",
        "太冲小吉与从魁，此是天门私出路。\n",
	"地户除危定与开，举事皆从此中去。\n",
        "六合太阴太常君，三辰元是地私门。\n",
        "更得奇门相照耀，出门百事总欣欣。\n",
        "太冲天马最为贵，卒然有准宜回避。\n",
        "但当乘取天马行，剑戟如山不足畏。\n",
        "三为生气五为死，胜在三难难逃五。\n"
});

void do_brood( object player, int skill, int degree )
{
	int mana, max;

	if( degree < 10  && (int)player->query("hit_points") > 20 &&
		skill > random(degree*degree*2) ) {
		message( "illusion", 
                        "你默想...."+c_illusion[random(23)],player );
		mana = (int)player->query("spell_points");
		max = (int)player->query("max_sp");
		player->add("hit_points",-3);
		if( mana + degree * 3 > max )
			player->set("spell_points", max );
		else
			player->set("spell_points", mana + degree * 3 );
		call_out( "do_brood", 3, player, skill, degree + 1 );
	} else {
	    player->delete_temp("meditating");
		player->delete_temp("block_defense");
		player->delete_temp("block_command");
//		player->delete_temp("block_message");
		tell_object( player,"突然你觉得脑中一片空白....。\n");
		tell_object( player,"然後周围的声音、景象逐渐由虚幻而具体，你从打坐中醒了过来。\n");
		tell_room( environment(player), 
			player->query("c_name")+ "睁开眼睛，看了看四周，站了起来。\n",
			player );
	    call_out( "quit_brood", degree*12, player );
	    player->set("next_brood", (int)player->query("age") + degree*12 );
	}
}

void quit_brood( object player )
{
    tell_object( player,set_color("你觉得精神又能集中了。\n","HIY") );
}

int cmd_brood()
{
	int brood_skill, hp;

	brood_skill = (int)this_player()->query_skill("brood");
	if( !brood_skill ) return notify_fail( 
		"你没有学过打坐的方法，可能会在打坐过程中迷失....。\n");
	hp = (int)this_player()->query("hit_points");
	if( hp <21 ) return notify_fail( 
		"你现在受伤过於沈重，无法打坐....。\n");
        if( this_player()->query_temp("exercising") ) return notify_fail("你正在聚丹，无法打坐...。\n");
	// Modified by Annihilator - to prevent quit-and-meditate bug
    if( (int)this_player()->query( "next_brood" ) >
        (int)this_player()->query( "age" ) )
      return notify_fail("你需要一段时间休息，才能再集中精神打坐....。\n");
	write("你席地坐了下来，集中精神，开始打坐....。\n");
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+ "席地而坐，闭上眼睛，开始打坐....。\n",
		this_player() );
	this_player()->set_temp("meditating", 1);
    if( !wizardp( this_player() ) ) {
 		this_player()->set_temp("block_defense", 1 );
 		this_player()->set_temp("block_command", 1 );
// 		this_player()->set_temp("block_message", 1 );
	}
	call_out( "do_brood", 3, this_player(), brood_skill, 0 );
	return 1;
}

int help()
{
    write(@HELP
指令格式： brood

这个指令使你坐下开始打坐，当你打坐的时候你的精神力(sp)会恢复的比平常快，
你打坐时间的长短是依据你的技能高低来判断，当你从打坐中醒来後会有一段时间
没有办法再打坐。
HELP
	);
    return 1;
}
