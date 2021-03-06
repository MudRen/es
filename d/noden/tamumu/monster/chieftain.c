#include <mudlib.h>
inherit MONSTER;

void create()
{
        object ob1, ob2;

        ::create();
        set_level(18);
        set_name( "sa-ba'tuka", "撒巴吐卡" );
        add( "id", ({ "chieftain", "tamumu", "tamumu chieftain" }) );
        set_short( "塔姆姆酋长 撒巴吐卡" );
        set_long(@C_LONG
撒巴吐卡是塔姆姆族的酋长，他不但是塔姆姆最伟大的战士，而且他
智慧也很高，你看到他的脸上有五道蓝色的刺青，代表他是塔姆姆族
最强壮的勇士。
C_LONG
                );
        set( "max_hp", 550 );
        set( "hit_points", 550 );
        set( "unit", "位" );
        set( "race", "human" );
        set( "gender", "male" );
        set( "alignment", -900 );
        set( "tactic", "berserk" );
        set_perm_stat( "str", 25 );
        set_perm_stat( "dex", 23 );
        set_perm_stat( "int", 20 );
        set_perm_stat( "pie", 14 );
        set_skill( "longblade", 100 );
        set_skill( "parry", 90 );
        set_skill( "block", 100 );
        set_skill( "tactic", 100 );

        set( "wealth/gold", 60 );
        set( "natural_armor_class", 70 );
        set( "natural_defense_bonus", 25 );
        set( "inquiry", ([
                "juraken":"@@ask_juraken",
             "flesheater":"@@ask_flesh"
                        ]) );

        ob1 = new( "/d/noden/tamumu/obj/sword" );
        ob1->move( this_object() );
        wield_weapon( ob1 );

        ob2 = new( "/d/noden/tamumu/obj/chief_shield" );
        ob2->move( this_object() );
        equip_armor( ob2 );
}

int ask_juraken()
{
        tell_object( this_player(),@LONG
撒巴吐卡大声的说道：哼！！可恶的裘拉根。当年发现他欲谋夺我们塔姆
姆族历代相传的宝藏，於是被我赶出来，想不到短短没几年，当年没有斩草除
根的後果就出现了：仗著自己学到了锡卡拉教的邪法，现在的裘拉根以经不是
简简单单可以应付的掉的。所以上次我们决定带肉食兽(flesheater)一起攻击
鸟人谷，因为肉食兽不怕裘拉根的锡卡拉结界。想不到作战到最激烈的时候，
用来控制肉食兽的宝珠竟然失去了魔力，发狂的肉食兽敌我不分，把我们塔姆
姆战士杀的血流如河，费了千辛万苦才擒服它，带了回来。也因此上次的作战
失败了，真是可惜啊~~~
LONG
        );
        return 1;

}

int ask_flesh()
{
        object obj;
        if (this_player()->query_temp("kill_juraken") != 1)
        {
                tell_object(this_player(),@LONG
撒巴吐卡说：食肉兽，是我们塔姆姆族世代相传保护著我们的圣兽，锐利
的爪子和强有力的牙齿撕碎敌人有如切菜一样简单。但是我们塔姆姆族有祖先
所留给我们的幻魔珠。这珠子的魔力可以使肉食兽的听从我们的命令。上次一
场大战，宝珠魔力消耗过大，因此失去了光芒。现在宝珠的魔力又补充好了，
如果你需要的话，只要帮我们杀死裘拉根，我就送你这颗宝珠。
LONG
                );
                return 1;
        }

        if (this_player()->query_temp("kill_juraken") == 1)
        {
                tell_object(this_player(),@LONG
撒巴吐卡说：嗯，谢谢你为我杀了裘拉根，上次讲好的谢礼就是这东东。

撒巴吐卡拿出了一颗血红色的珠子。
撒巴吐卡说：拿著这颗宝珠，走到食肉兽旁，喃喃的念著"ern!-sdl"就可降伏
那头魔兽。
LONG
                );
		obj = new( "/d/noden/hawk/obj/pearl" );
                obj -> move(this_object() );
                command("give pearl to " + this_player()->query("name") );
                call_out("part2",5,this_player() );
                return 1;
        }
        return 1;
}


int part2()
{
        tell_object(this_player(),@LONG
撒巴吐卡告诉你：对了，你要得到神明的认可才行喔。也就是说要帮助在天上的
诸神取回他们流落人间的宝物。否则宝珠就没有用了。
LONG
        );
        return 1;
}
