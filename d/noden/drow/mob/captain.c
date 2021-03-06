#include "/d/noden/drow/iigima.h"

inherit MONSTER ;

void create ()
{

        ::create();
        set_level(15);
        set_name( "Captain Shukaise","侍卫队长修凯思" );
        add ("id", ({ "drow", "captain","shukaise" }) );
        set_short( "Captain Shukaise","侍卫队长修凯思" );
        set("unit","位");
        set("alignment",700);
        set("weight",400);
        set("wealth/copper",6000);
        set_long(
@C_LONG
这位英勇的战士是黑暗精灵村的侍卫队长，也是士兵们的领导者
，他看来已经有四十来岁了，但炯炯有神的目光环绕四周，他现
在正在为士兵的排班休假的问题烦恼著。
C_LONG
        );
        set_perm_stat("int", 20);
        set_perm_stat("dex",14);
        set_perm_stat("str",21);
        set("max_hp",480);
        set("hit_points",480);
        set_natural_weapon(20,10,20);
        set_natural_armor(32,15);
        set ("inquiry",([
                "certification" : "@@ask_certification",
                        ]) );
        set ("special_defense",(["all":30, "cold":-10,
                        "fire":-10, "divine":-30,"evil":30, "none":15]));
        set ("race", "drow");
        set ("gender", "male");
        set_skill("longblade",70);
        set_skill("dodge",60);
        set_skill("parry",70);
        set_skill("block",75);
        set_c_limbs(({"身体","头部","脚部","手臂"}));
        wield_weapon(OBJ"scale_lb");
        equip_armor(ARM"plate");
        equip_armor(ARM"shield");
        equip_armor(ARM"arms");
        equip_armor("/d/noden/asterism/armor/leggings02.c");
}

void die()
{
        object obj,who;
        tell_room(environment(this_object()),
                "侍卫队长说道：你......你...你好坏哦~~~~~~。\n");
        ::die(1);
}

int ask_certification()
{
        object obj;
        if (!this_player()->query_temp("drow_certi")
                || this_player()->query_temp("drow_certi") == 3 )
        {
                tell_object(this_player(),@LONG
队长吆喝道：去去，小朋友不要在这边捣蛋，没看到我在忙吗？
LONG
                );
                return 1;
        }

        if (this_player()->query_temp("drow_certi") == 1 )
        {
                tell_object(this_player(),@LONG
队长抬起头来上下打量了你一番，点点头说：嗯，那我们比划两招吧，
看看你够不够格称的上是一名勇者，为了避免别人的打扰，我带你到军营
里的教练场吧。
LONG
                );
                tell_room(environment(this_object()),
                        "你看到"+(string)this_player()->query("c_name")+
                        "跟著修凯斯队长走进军营里。\n",this_player() );
                this_player()->move_player("/d/noden/drow/square1.c","SNEAK");
	call_out("message",5,this_player() );
                return 1;
        }

        if (this_player()->query_temp("drow_certi") == 2 )
        {
                tell_object(this_player(),@LONG
修凯斯队长说道：嗯，我以经听到巴图的报告了，这个徽章让你带在身上，
村长就会知道我的意思了。
LONG
                );
                obj = new("/d/noden/drow/obj/mark");
                obj->move(this_object() );
                command("give seal to "+(string)this_player()->query("name") );
                this_player()->set_temp("drow_certi",3);
                return 1;
        }
        return 1;
}
void message()
{
	tell_object(this_player(),@LONG
你听到修凯斯队长的声音从空中传来：小朋友，往南走一格就可以
碰到这次比武的主试者，想办法打败他吧。
LONG
	);
}
