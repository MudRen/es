#include "/d/mage/mage.h"
 
#define TMP_FILE "/tmp/wall."+getoid(this_player())
#define WALL_FILE "/d/mage/data/wall.txt"
 
inherit ROOM;
 
 
 
int process();
 
void create()
{
	
	::create();
	
	set_short("Ä§·¨Ê¦¹«»áÃûÈËÌÃ");
	
	set_long(@TEXT
ÕâÀïÊÇÒøËşµÄµØÏÂÊÒ. Î÷ÃæÊÇÒ»Æ¬Í¿Ñ»Ç½ (wall). ÕıÇ°·½Á¢ÁË¼¸¸öÊ¯±®. (slab)
±±±ßÇ½¹ÒÁË¸öÅÆ×Ó (sign). µØÃæÉÏĞ´ÁË¼¸¸ö´ó×Ö:
 
À­ÀÏ´óµ½´ËÒ»ÓÎ!
 
 
TEXT
	);
	
	set("item_desc", ([
	"sign" : @SIGN

©°¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª©´
©¦ Ä§·¨Ê¦¹«»áÃûÈËÌÃ:                                              ©¦
©¦ 0. ÕâÀïÏÖÈÎµÄ¸ºÔğÈËÊÇboss                                      ©¦
©¦ 1. ÒªÁ¢±®µÄÇëÕÒÎÒ,²¢ÇëËµÃ÷ÀíÓÉ(ÈçÄãÄ³ÏîÄ§·¨µÚÒ»¸öÁ·µ½¶¥)       ©¦
©¦ 2. ÒªÔÚÍ¿Ñ»Ç½Ğ´×ÖµÄ: write wall                                ©¦
©¸¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª©¼
 
µ×ÏÂÓĞÒ»ĞĞĞ¡×Ö: Jdw ²»ÒªÔÚÕâÀï med À²..
SIGN
	,
	"slab" : @SLAB

                ´   ©°¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª©´
                ¦   ©¦      boss      ©¦
                ¦   ©¦  (²¨²¨Ê¿Ê¿)    ©¦
                ¦   ©¦     Ç          ©¦
                ¦   ©¦      Ä§å       ©¦
                ¦   ©¦      ·¨ì       ©¦
                ¦   ©¦      ¹««       ©¦
                ¦   ©¦      »á        ©¦
                    ©¦      µÚ        ©¦
                ¦   ©¦      ¶ş        ©¦
                ¦   ©¦      ÈË        ©¦
                    ©¦²»×¼¸æÎÒÀÄÓÃÖ°È¨©¦
                ¼   ©¸¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª©¼
 
SLAB
,
    "wall" : "@@read_wall",
	]) );
	set("exits", ([
 
	"up" : MAGE"mage_guild",
	"down" : MAGE"storage",
 
	]) );
 
	set("pre_exit_func", ([
	"down" : "to_go_down",
	]) );
 
//	set("objects", ([
//	"worker" : MAGE"npc/worker",
//	]);
}
 
void init()
{
	add_action("write_wall","write");
//	if ((string)this_player()->query("name") == "karrimor") {
//		add_action("settitle","title");
//	}
}
/*
int settitle(string str)
{
	if (!str) return notify_fail("Syntax: title <title to set>\n");
this_player()->set("title",str+" "+(string)this_player()->query("c_name"));
	return 1;
}
*/ 
int write_wall(string str)
{
	if (!str) return notify_fail("ÄãÒªĞ´ÄÇÀï°¡?\n");
	if (str != "wall") return notify_fail("²»ÒªÂÒ»­à¸... \n");
    write("¿ªÊ¼ÊäÈëÎÄ×Ö....\n");
	this_player()->edit(TMP_FILE, "process", this_object());
	return 1;
}
 
int process()
{
	string text, title;
    seteuid(getuid());
    text = read_file(TMP_FILE);
    rm(TMP_FILE);
    title = (string)this_player()->query("c_name")+" ì¶ "+
        "/adm/daemons/weather_d"->query_c_game_time()+" Ğ´ÏÂ:\n";
    write_file(WALL_FILE, title+text+"\n");
    write("Ok.\n");
	return 1;
}
 
string read_wall()
{
	this_player()->more(WALL_FILE);
	return "\n";
}
 
int to_go_down()
{
	if (wizardp(this_player()) || (this_player()->query_level() >= 
10) ) 
		return 0;
	tell_object( this_player(), "Ò»µÀÄ§·¨Á¦³¡µ²×¡ÁËÄãµÄÈ¥Â·\n");
	return 1;
}

