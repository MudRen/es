#include "../iigima.h"

inherit MONSTER ;

void create ()
{

        ::create();
        set_level(9);
        set_name( "Drow village leader","老村长");
        add ("id", ({ "drow", "leader" }) );
        set_short( "Drow village leader","老村长");
        set("unit","位");
        set_long(
@C_LONG
他的年纪一大把却仍然担任著村内的协调工作，他就是黑暗精灵村的
老村长，最近神官执意将一位女祭司送往神坛祭祀，似乎造成了老村　
长的烦恼(trouble)，你可以帮帮他吗？
C_LONG
        );
        set_perm_stat("str", 12);
        set_perm_stat("dex", 11);
        set_natural_weapon(10,6,9);
        set_natural_armor(25,10);
        set( "special_defense",
                (["all":15,"fire":-10,"cold":-10,
                        "evil":30,"divine":-30,"none":5 ]) );
        set("gender", "male");
        set("wealth/copper",500);
        set("weight" , 700);
        set ("race", "drow");
        set( "inquiry", ([
                "trouble" : "女祭司吗？唉．．可怜的蒂德，谁能去帮(help)她呢？ \n",
                "help" : "蒂德被神官送到司娜可神殿(temple)了，就已经献给神了，要如何救她呢？\n",
                "temple" : "喔．．神殿平常人是不能进去的啦，除非是勇者(valor)的传人才能进入啦！\n",
                "valor" : "@@ask_valor",
      "mark" : "还问？你到底要不要去拿啦？\n",
               ]) );
        wield_weapon(OBJ"copper_blunt");
        equip_armor(ARM"bracers");
        equip_armor(ARM"ring1");
}

int ask_valor()
{
        tell_object(this_player(),@LONG
村长说：唷，你也觉得自己是是勇者吗？前几天来玩的都说是勇者，
结果都骗我～～～所以，我决定，除非你能得到修凯思的认可，能通过他
的考验并且拿他的徽章(mark)给我，证明 (certification)你是勇者，我
再教你如何靠近神殿！
LONG
        );
        this_player()->set_temp("drow_certi",1);
        return 1;
}


int accept_item(object me, object item)
{
        string name;
        object ob;

        name=(string)item->query("name");
        if (!name || (name!="captain's seal"))
                return 1;

        write("老村长说：嗯，是徽章没错，你等等．．．．\n");
        if (!this_object()->query("scale"))
        {
                write("老村长说：拿去吧，这片蛇鳞得来不易，相信对你会有帮助的。\n");
                ob=new(OBJ"scale");
                ob->move(this_player());
                set("scale",1);
        }
        else
                write("老村长慢慢的说道：真可惜，有人也给我徽章了，你的是仿冒品吧！\n");
                return 1;
}
// QCing.
