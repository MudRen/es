// Adventurer Delta Zeus
//
//		Lilia

#include "../lilia.h"

inherit MONSTER;

void create()
{
    ::create();
    seteuid(getuid());
    set_level(1);
    set_name("Delta Zeus", "考古学家 达特纽斯");
    add("id", ({"delta", "zeus"}));
    set_short("考古学家 达特纽斯");
    set_long(@C_LONG
站在你面前的这位先生，就是顶顶大名的考古学界鬼才达特纽斯，也是个
非常有名的冒险家。达特纽斯先生前些日子为了考查传说中的魔族古帝国遗迹
而失踪了，没想到竟出现在这里，或许你可以问问他有关遗迹 (ruin) 的事情
来满足一下你小小的好奇心。
C_LONG
	    );
    set("gender", "male");
    set("race", "human");
    set("unit", "个");
    set("no_attack", 1);
    set("inquiry", ([
	"ruin" : "@@ask_ruin",
	"rune" : "@@ask_rune"
	]) );
}

void ask_ruin(object p)
{
    tell_object(p, @RUIN
遗迹? 呵呵呵 .... 年轻人，你现在就站在魔族古帝国第一大城罗斯托丽
城的土地上啦! 如果你对魔族古帝国的事迹有兴趣的话，这里是最好的教室，
但是得要你自己努力去寻找才行。
RUIN
	);
    return;
}

void ask_rune(object p)
{
    object dic, *items;
    int i;

    tell_object(p, @RUNE
哦，那个碑文啊? 那是古代魔族的文字，碑文里面只写了四个字：「芝麻
开门」，我还没推敲出来它的意思呢。年轻人，如果你对魔族的碑文有兴趣，
这本魔法字典送给你，它可以帮助你阅读魔族的古文。
RUNE
	);
    items = all_inventory(p);
    for (i = 0; i < sizeof(items); i++)
   	if ((string)items[i]->query("name") == "Rune Dictionary")
	{
	    tell_object(p, "咦? 你已经有这本字典啦? 那我还是留著好了。\n");
	    return;
	}

    dic = new(OBJ"dictionary");
    dic->move(p);
    p->set_temp("lilia_dic", 1);
    return;
}

