#include <mudlib.h>
#include "../hawk.h"
inherit MONSTER;

// 这只算是半完成品吧 ..... 如果 QC 时特攻还有问题就先把特攻关掉

void create ()
{
        object obj1,obj2,obj3,obj4;
        ::create();
        set_level(19);
        set_name("Hawkman Chief Flamen","鸟人族总祭司");
        add("id",({"","hawkman","flamen"}) );
        set_short("鸟人族总祭司");
        set_long(@C_LONG
你看到一个白发苍苍的鸟人，身上的羽毛都已经脱落了，但是依然神采亦
亦的站在大厅，看来他一定会长命百岁的。他主管著左右两扇门(door)後的
祭坛。他发现了你正看著他，於是转过头对你和蔼的笑了一下。
C_LONG
        );
        set( "gender", "male" );
        set( "race", "hawkman");
        set( "unit", "位" );
        set("inquiry",([
              "square":"@@ask_square",
                "door":"@@ask_door",
	"destroy":"@@ask_destroy",
                        ]) );
        set( "alignment",-800);
        set_perm_stat( "dex", 15 );
        set_perm_stat( "str", 15 );
        set_perm_stat( "int", 27 );
        set_skill( "dodge" , 100 );
        set_skill( "unarmed" , 50 );
        set ("max_hp", 1000 );
        set ("hit_points", 1000 );
        set_natural_weapon( 53 , 28 , 45 );
        set_natural_armor( 10 , 20 );
        set( "aim_difficulty",
                ([ "critical":40,"weakest":70,"ganglion":30,"vascular":50 ]) );
        set ("special_defense",([
                "monk": 20, "scholar": 20, "evil": 80,
                "divine": -20, "all": 30]) );
        set( "tactic_func","my_tactic");
        equip_armor(ARMOR"magerobe.c");
        equip_armor(ARMOR"star_arm.c");
        obj1 = new(OBJ"square_obj");
        obj2 = new(OBJ"square_obj");
        obj3 = new(OBJ"square_obj");
        obj4 = new(OBJ"square_obj");
        obj1->move(this_object() );
        obj2->move(this_object() );
        obj3->move(this_object() );
        obj4->move(this_object() );

}


int ask_door()
{
        tell_object(this_player(),@LONG
鸟人族总祭司对你亲切的笑了一笑，说：
    左右两扇门都可以通到武斗场(square)，不过善良的与邪恶的却有不一
样的路，想想你一路走来，你所走的路正指引著你该往哪走....不过，邪恶
的人啊，请往黑暗的路走吧。
LONG
        );

        return 1;
}

int ask_square()
{
        tell_object(this_player(),@LONG
总祭师说：
    武斗场是我们鸟人族的比武的地方，不过最近多了一些邪恶的怪物盘踞在
里面，如果有人肯进去帮我们消灭(destroy)那些怪物的话，那该有多好。
LONG
        );
        return 1;
}

int ask_destroy()
{
        if (!present("amulet",this_object() ))
        {
                tell_object(this_player(),@LONG
鸟人祭师说道:
嗯....今天已经太多人跟我说要帮忙了，可是因为竞技场是由神圣的结界所支
撑的，没办法让太多人进去，你还是等下次吧。
LONG
                );
                return 1;
        }

        tell_object(this_player(),@LONG
鸟人祭师说道:
哦，你愿意帮助我们吗? 送你这个护身符, 可以当做武斗场的入场证明
LONG
        );
        command("give amulet to "+(string)this_player()->query("name") );
        return 1;
}


int my_tactic()
{
        object victim,tape;
        string name;
        int dex,choice;
        if (!victim = query_attacker()) return 0;
        name =(string)victim->query("c_name");
        dex = victim->query_perm_stat("dex");
        if( !victim ) return 0;
        choice = random(4);
        switch(choice)
        {
                case 0 : return 0;
                         break;

                case 1 :
                if ( random(dex) > 15 ) return 0;
                if ( victim->query_temp("no_hearing") ) return 0;
                tell_room(environment(victim),"\n老祭司伸出双手，飞快的在"+
                        name + "的双耳轻拍一下。\n",victim);
                tell_object(victim,@C_LONG
老祭司伸出双手，在你的双耳上轻拍了一下，你顿时感到双耳一阵剧痛。
............
[你聋了。]
C_LONG
                );
                victim->set_temp("no_hearing",1);
                victim->receive_special_damage("none",30);
                victim->set_temp("block_message",1);
                return 1;
                break;

                case 2 :
                if ( random(dex) > 12 ) return 0;
                if ( victim->query_temp("no_sight") ) return 0;
                tell_room(environment(victim),
                        "\n老祭司伸出右手虚晃一招，忽然用左手"
                        + "的食中二指往"+ name + "的双眼插去，只见"+ name
                        + "痛得在地上滚来滚去。\n",victim);

// 如果耳朵已经聋了就看不到下面的 message .... 不知道怎麽办ㄌㄟ ....

                tell_object(victim,@LONG
老祭司伸出右手虚晃一招，忽然左手飞快的往你脸上招呼，食中二指正中
你的双眼。你双眼一阵巨痛，恐怕是凶多吉少。
[ 你瞎了。]
LONG
                );
                victim->set_temp("no_sight",1);
                victim->receive_damage(15);
                victim->set("blind",1);
                return 1;
                break;

                case 3 :
                if ( victim->query_temp("no_sound") ) return 0;
                if ( random(dex) > 12 ) return 0;
                tell_room(environment(victim),
                        "\n老祭司身形飘渺, 忽然一记重拳直击在"
                        + name + "的喉咙，只见" + name
                        +"脸色大变。\n",victim);

                tell_object(victim,@LONG
老祭司一记重拳正中你的喉咙，你只觉得他似乎微微捏了你的喉头一下，
接著就发现你一个字都讲不出来了~~~~~

[ 你哑了。]
LONG

                );

                victim->receive_damage(30);
                victim->set_temp("no_sound",1);
                tape=new(OBJ"tape");
                tape->move(victim);
                return 1;
                break;

                }
        return 1;
}
