inherit MONSTER;
#include "../hawk.h"
int help1 = 0;
void create()
{
        ::create();
        set_level(8);
        set_name( "tailor","裁缝师" );
        add("id",({"tailor"}) );
        set_short( "裁缝师" );
        set_long(@LONG
你看到一个年纪不轻的裁缝师，多年的工作经历使得她对於缝纫工作架轻就熟，
不过你看她神色似乎不善，可能是顺手的工具不见了，你如果能帮忙(help)她找回
她的东西，可能会对你满有帮助的。
LONG
        );
        set( "inquiry", ([
                "help" : "@@help_me",
                "dry" : "@@dry_paper"]));
        set( "alignment", 100 );
        set( "gender","female" );
        set( "race","gnome" );
        set( "time_to_heal", 10 );
        set_natural_armor( 20, 12 );
        set_natural_weapon( 25 , 13 , 17 );
        set( "wealth/silver", 10 );
}

int dry_paper(object who)
{
        object paper1;
        if (this_player()->query_temp("help_tailor") == 0)
        {
                tell_object(this_player(),
                "你想把东西烘乾啊？要用热的东西去烘啊。如果不会的话，我"+
                "可以帮你烘，但\n是你要先帮我(help)做点事。\n");
                return 0;
        }

        if (this_player()->query_temp("help_tailor") == 2)
        {
                tell_object(this_player(),
                "你要烘啥东西啊，小心不要烧掉了，还是我来帮你好了。\n");

                if (!present("paper",this_object()))
                {
                        tell_room(environment(),
                        "裁缝师说：你纸不给我的话，我可没办法帮你唷。\n",
                        this_object()
                                 );
                        return 1;
                }

                tell_room(environment(),
                        "裁缝师帮"+(string)this_player()->query("c_name")+
                        "把他手上的小纸片烘乾了。\n",this_object()
                         );
                paper1 = new(OBJ"paper1.c");
                paper1->move(this_object());
                command("give paper to "
                        +(string)this_player()->query("name"));
		this_player()->set_explore("noden#41");
                return 1;
        }
}

int help_me()
{
        if (this_player()->query_temp("help_tailor") == 2)
        {
                tell_object(this_player(),
                        "裁缝师说：为了感谢你帮我找到了我的熨斗，有什麽需要"+
                        "我帮忙的你就尽管说吧。\n" );
                return 1;
        }

        if (this_player()->query_temp("help_tailor") == 1)
        {
                if (!present("iron") )
                {
                        tell_object(this_player(),
                        "裁缝师说：非常谢谢你帮助我，请你把熨斗还给我吧。\n" );
                }
                else if (present("iron") )
                {
                        tell_object(this_player(),
                        "裁缝师拿起熨斗高兴的叫: 『 啊~~~~我又可以回"+
                        "去做我的工作罗。』\n");
                        command ("kiss " +
                           (string)this_player()->query("name"));
                        this_player()->set_temp("help_poet",2);
                }
        return 1;
        }
	if (help1 == 1)
	{
		tell_object(this_player(),@LONG
裁缝师说：嗯，有个大有为的年轻人说要帮我找了，那就谢谢你的好意了。
LONG
		);
		return 1;
	}
		
        tell_object(this_player(),@LONG

裁缝师看了你一眼，说：
    很久以前啊，我曾经遗失了一个熨斗，不知道掉在哪里，不过我猜有可能是
在一阵被山贼追赶的混乱中掉的。希望你能帮我找回来，如果找回来的话，有什
麽我能帮的上忙的，尽管开口吧。
LONG
        );
	help1 = 1;
        return 1;
}

