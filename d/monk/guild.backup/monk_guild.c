
#include "saulin_temple.h" 
#define  BOARD "/d/monk/guild/monk_board"

inherit GUILD;

void create()
{
	::create();
	set_short("A monk guild", "罗汉堂");
	set_long( @LONG_DESCRIPTION
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
一踏进罗汉堂你的眼光马上被两旁供奉的十八罗汉所震摄。降龙、伏虎、迦叶、阿难
．．．  十八尊罗汉塑像之神态姿势各不相同。他们分立在左右墙边，墙後的壁画绘著每
名罗汉得道成佛的过程。
少林罗汉堂是少林寺中武僧们互相切磋武学的地方，不少僧人目前正在此处练功\、舞棍及
讨论武技，拳来脚往刀光剑影的十分热闹。如果你想加入少林武僧的行列，你可以在这里 
得到相关的资讯。你发现罗汉堂角落的墙上(wall)被人用金刚指力刻了一些字。  
东、南、北方的三个出口，分别通往三类练功\房，西方则可以回到穿堂。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "c_item_desc", ([ 
          	"wall" : @LONG_TEXT
————————————————————————————————
罗汉堂是所有少林僧人学习武艺之处，也有人称它是少林和尚公会。
『众生无我  一切随缘』，除了吸血的吸血鬼和没有手的眼魔外，我 
们都欢迎你来加入，但少林百年寺规□□□本地不招待女客，所以如
果你是女子，请恕本堂无法让你加入(join)。

help guild 可以得到进一步的公会指令说明。
help monks 可以得知少林和尚公会的属性限制及说明。

另外你要特别注意
『本寺武僧若犯戒杀害任何玩家，经被害人申诉属实者，杀无赦』  
 即本公会严禁ＰＫ任何人，但若为防身自卫则不算　　
————————————————————————————————
LONG_TEXT
 ]) );
	set( "exits", ([ 
	        "south": SAULIN"gonfu_room4",
 	        "east" : SAULIN"gonfu_room1",
 	        "west" : SAULIN"monk_pass",
                "north": SAULIN"gonfu_room3" ]) );
	set( "no_monster", 1 );
	set( "objects", ([
		"Monk" : SAULIN_MONSTER"shan-chi" ]) );
	                 BOARD->frog();
	set_guild( "monk" );
        set( "pre_exit_func", ([    "north" : "check_monk",
                                    "south" : "check_monk",
                                    "east"  : "check_monk" 
	])  ); 
reset();
}

int check_monk()
{   
        if( wizardp( this_player() ) ) return 0; 

 if( (string)this_player()->query("class")!="monk" && present("shan chi") ) {
//if( (string)this_player()->query("class")!="monk"  ) {
		write( can_read_chinese()?
                "玄慈双手合十，揖身道曰：「这位施主对不起，少林禁地只有少林武僧才能进去。」\n":
			"Sorry, that is for monk only.\n" );
		return 1;
	}
	
  if( (int)this_player()->query("alignment")<-200 && present("shan chi") ) {
		write( can_read_chinese()?
"玄慈怒目而视道曰：「身为少林武僧在外为非做歹，还想回来学武艺!!!」\n":
			"Get out of here!!!\n" );
		return 1;
	}
	return 0;

}
