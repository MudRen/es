#include <mudlib.h>;
#include <config.h>;

inherit OBJECT;
inherit DAEMON ;

int read_me = 0;

void create()
{
        seteuid(getuid());
        set("id",({"story"}));
        set_name("story","东方故事集");
        set_short("东方故事集");
        set_long(
                "这是一本记载东方大陆的古老传说的故事集。\n");
        set( "weight", 30 );
        set("unit","本");
        set("value",({20,"silver"}) );
}

void init()
{
  add_action("read_me", "read");
}

int read_me (string str)
{
        object who,monster;
        who=this_player();
        
        if (!str)        
            return notify_fail("你要读什麽东东呀?\n");
                 
        if (str!="story")     
            return 0;

        if (!read_me)
{
        say(who->query("c_name")
                +"正在读一本书，书名是「东方故事集」。\n");
        tell_object(who,@LONG
书上记载著:
传说在海的那一边有个古老的国家，名叫东方大国。在那里的人们都锦衣玉食，
遍地成金.......

咦? 後面的书页都不见了, 好像是被虫给蛀光了呢!
LONG
        );
        if ( (int)who->query_quest_level("bookbug") > 0 )
        return 1;

        tell_object(who,@LONG
当你翻阅故事集时, 忽然一只肥嘟嘟的书虫从书本中掉了出来!
LONG);
        monster = new( "/d/noden/farwind/monster/bookbug" );
        monster->move(environment(who));
        who->set_temp("findbug",1);
        read_me = 1;
        return 1;
}
        tell_object(who,@LONG
你仔细的阅读书上所写的字，企图辨认上面所写的字，不过实在
是被虫蛀的太严重了....你越想越生气，实在想把可恶的蛀书虫
找出来一脚踩死泄忿。
LONG
        );
        return 1;
}

