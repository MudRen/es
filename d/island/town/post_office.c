// post_office.c
#include "../island.h"
#include <mailer.h>

inherit ROOM;

void create()
{
	::create();
	seteuid(getuid()) ;
	set_short("民营邮局");
	set_long(@C_LONG
你现在位於映世村的邮局，因为这村落是位在中立区，所以邮局是当
地民营的；在这里你可以寄信(mail)给其它不在线上的人，若是有人寄信
给你，也可以在这里领取。在柜台旁边的墙上有一张布告(sign)说明如何
寄信收信。
C_LONG
	);
	set("light",1) ;
	set("exits", ([ "west" : ITOWN"town02" ]) ) ;
	set("pre_exit_func", ([ "west" : "dest_mailer" ]) ) ;
	set("item_func", ([ "sign" : "read_sign" ]) ) ;
}

void init()
{
	add_action("mail", "mail") ;
	add_action("help", "help");
	add_action("read_sign", "read") ;
        if( this_player() ) this_player()->set_explore( "eastland#8" );
}

int mail(string arg)
{
   object ob;

   seteuid("TEMP");

   ob = new(MAILER);
   ob->move(this_player());
   ob->start_mail(arg);
   return 1;
}

int help(string str)
{
    if (str == "mail") {
	this_player()->more(MAILER_LONG);
	return 1;
    } else return 0;
}

int read_sign (string str)
{
	if (str && str!="sign") return 0 ;
	write (@LONG
        如何收信，寄信：
        
        □ 收信 ： 键入 mail ，你将进入读信的状态 。 用 ? 可在
                   读信状态下，得到help。
        □ 寄信 ： 格式是 mail [ppl's id] 。
LONG
     ) ;
	return 1 ;
}

int dest_mailer()
{
	object ob ;

	ob = present("mailer",this_player());
	if (ob) ob->remove() ;
	return 0 ;
}
