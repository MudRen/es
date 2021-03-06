// Archfiend
//
//		Lilia

#include "../lilia.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name("Archfiend", "黑天使 亚奇芬德");
    add("id", ({"archfiend", "devil"}));
    set_short("黑天使 亚奇芬德");
    set_long(@C_LONG
狞笑的面孔，黑亮的翅膀，外加头上的三只角，不用说你也知道站在你面
前的是冥府的老大黑天使亚奇芬德，外号撒旦的便是。看来想要走出这里，必
须和他老人家谈笔交易 (trade) 才成。
C_LONG
	    );
    set("gender", "male");
    set("race", "vampire");
    set("unit", "位");
    set("no_attack", 1);
    set("inquiry", ([
	"trade" : "@@ask_trade",
	"dedicate" : "@@ask_dedicate",
	"question" : "@@ask_question"
	]) );
}

void init()
{
    ::init();
    add_action("to_answer", "answer");
}

void ask_trade(object p)
{
    tell_object(p, @TRADE
亚奇芬德斜著眼打量了你好一会儿，然後慢条斯理的说道：「你想找齐七个封
印好去见那个变态女王啊? 真是勇气可嘉呀! 为了表示我对勇者的崇敬，你可
以选择把你的灵魂奉献 (dedicate) 给魔鬼，或是回答我的谜题 (question)
来得到我手中的弗雷斯之印。不过我先警告你，如果你没有办法正确地回答我
的谜题，那你的灵魂会自动地奉献给魔鬼，而且你也得不到弗雷斯之印。至於
灵魂要怎麽奉献嘛 .... 等你到了远风镇你自然会明白呵呵。决定好了之後，
问 (ask) 我奉献 (dedicate) 或谜题 (question)。」
TRADE
	       );
    return;
}

void ask_dedicate(object p)
{
    tell_object(p, "亚奇芬德大笑道：「好个爽快的家伙，我会叫黑无常拿弗雷斯印给你！」\n");
    this_player()->set(QUESTNAME, 4);
    tell_object(p, "一阵霹雳闪电忽然打在你的身上，你感到眼前一黑 ...\n");
    tell_room(environment(p), "亚奇芬德发出了一阵狂笑，随即召唤来一阵天雷直直地劈在"+p->query("c_name")+"的身上！\n", p);
    this_player()->receive_damage(2000);
    return;
}

void ask_question(object p)
{
    tell_object(p, @QUES
亚奇芬德说道：「只要你告诉我，东方故事里最变态的巫师是谁，答对的话，
我就履行我的诺言。你不必急著回答我，当然，答错了的话，你必须付出你的
生命当代价。」
QUES
	       );
    this_player()->set_temp("lilia_devil", 1);
    return;
}

int to_answer(string s)
{
    object p;
    p = this_player();

    if (!s || p->query_temp("lilia_devil") != 1 || p->query(QUESTNAME) >= 4)
	return notify_fail("你想答什麽？\n");

    if (s != "lilia" && s != "调教师" && s != "女王")
    {
	tell_object(p, "亚奇芬德大笑道：「这麽简单的题目也不会？死来！」\n");
        tell_object(p, "一阵霹雳闪电忽然打在你的身上，你感到眼前一黑 ...\n");
        tell_room(environment(p), "亚奇芬德发出了一阵狂笑，随即召唤来一阵天雷直直地劈在"+p->query("c_name")+"的身上！\n", p);
        p->receive_damage(2000);
    }
    else
    {
	tell_object(p, @LAUGH
亚奇芬德大笑道：「聪明的家伙，一屁中弹！我已经履行了我的诺言，
把弗雷斯印送给你了。顺便做点沙密斯给你好了，你要记好，在死亡迷
宫里，要依著女王的名前进。去吧！聪明的家伙！」
LAUGH
		   );
	tell_object(p, "亚奇芬德啪的一声在你头上打了一记，你觉得眼前一黑 ....\n");
        write("[你完成了 失落的封印 第二阶段的任务，获得 2000 点经验]\n");
        this_player()->finish_quest(QUESTNAME, 2);
        this_player()->gain_experience(2000);
	this_player()->set(QUESTNAME, 4);
	p->move(AREA"rose4");
    }

    return 1;
}   
