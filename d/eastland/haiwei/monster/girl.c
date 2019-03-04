#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "tea girl", "卖茶姑娘" );
	add( "id", ({ "girl" }) );
	set_short( "卖茶姑娘" );
	set_long(@C_LONG
这位卖茶姑娘看起来大概只有十五、六岁，她笑起来脸上有著甜甜
的酒涡。
C_LONG
   	        );
	set( "gender", "female" );
	set( "race", "human" );
	set( "no_attack", 1 );
	set( "chat_chance", 10 );
	set( "chat_output", ({
		"卖茶姑娘愉快地对著你微笑。\n",
		"卖茶姑娘说道: 大爷进来喝杯茶，歇歇腿吧。\n",
		"卖茶姑娘说道: 我们的茶远近驰名，清凉止渴。\n",
		"卖茶姑娘说道: 欢迎光临，请这边坐。\n"
	}) );
        set( "inquiry", ([
	        "diet": "@@ask_diet",
	        "brother": "@@ask_brother"
        ]) );
}
void init()
{
    ::init();
    add_action("do_answer","answer");
}
int ask_diet()
{
command("look "+(string)this_player()->query("name"));
if (!(this_player()->query_temp("fat_quest/diet")) || this_player()->query_temp("fat_quest/diet")<1) {
write(
"卖茶姑娘赏了你一巴掌，骂道: 我身材这麽好? 需要减肥吗??\n");
}
else {
write(
"\n卖茶姑娘说道: 没错，我们是有卖减肥茶，但是我就快下班了，你可不可以明天\n"
"再来??\n");
command("giggle "+(string)this_player()->query("name"));
return 1;
}
}
int ask_brother()
{
if (this_player()->query_temp("fat_quest/diet")<1) {
write(
"卖茶姑娘说道: 你是谁啊? 干嘛问东问西的...\n");
return 1;
}
else {
write(
"\n卖茶姑娘说道: 没错，我是有一个哥哥，叫作安道全，生性刁蛮古怪，从小就不\n"
"太照顾我，一天到晚都帮人治病去；不过因为他是我唯一的哥哥，我也对他很尊敬，\n"
"有一天，他有一个病人送我一颗大珍珠，由於我自小就非常喜欢珍珠，所以他就把珍\n"
"珠送给我，但是他随口亏了我几句，我气不过就离家出走啦，现在想想，我也真是幼\n"
"稚............................\n\n");
call_out("ask_brother1",10,this_player());
return 1;
}
}
int ask_brother1()
{
write(
"卖茶姑娘继续说道: 你身上有药味，是我哥叫你来的吧? 他这个人倒还好，只是\n"
"嘴巴太毒了，不过他毕竟是我哥哥，等店里的生意告一段落，我会回去看看他的\n");
return 1;
}
int accept_item(object me,object item)
{
	string name;
	name=(string)item->query("name");
     if ( !name || (name!="blue pearl" && name != "pearl ring" && name != "Moon pearl") ) return 1;
	if (name == "pearl ring")
{
     tell_object(me,
@RING
卖茶姑娘接过珍珠戒指，端详了几眼，说道: 这是默尔斯人作的假珍珠。你对著光照
照看，就会看到许\多小小气泡。说完，卖茶姑娘把戒指还给你.....
RING
	);
        command("give "+name+" to "+(string)this_player()->query("name"));
        return 1;
}
     if (name == "blue pearl")
{     
     tell_object(me,
@BLUE
卖茶姑娘接过蓝珍珠，看了几眼後摇摇头说道: 这蓝珍珠虽然是真品，而且又很漂亮，
可是根据默尔斯人的讲法，蓝色是因为受到魔法元素污染的结果，常常把玩，对身体
会有不好的影响，你最好小心一点。说完，卖茶姑娘把戒指还给你.....
BLUE
	);
        command("give "+name+" to "+(string)this_player()->query("name"));
        return 1;
}
     if (name == "Moon pearl")
{     
     tell_object(me,
@MOON
卖茶姑娘接过夜明珠，两眼忽然一亮，开始把玩这颗大珍珠，脸上流露出爱不释手的
表情........
MOON
	);
	item->remove();
call_out("play_pearl",20,this_player());
	return 1;
}
}		
int play_pearl(object me)
{
write("十分钟以後，卖茶姑娘终於抬起头来，说道: 这颗珍珠真不错，你是要拿来送我的吗?\n"
      "(answer yes or no)...........\n");
		me->set_temp("fat_quest/diet",2);
        return 1;
}
int do_answer(string arg,object ob1)
{
   if (this_player()->query_temp("fat_quest/diet")<2) return 0;
   if (this_player()->query_temp("fat_quest/get_tea")) return 0;
   if ( !arg || (arg != "yes" && arg != "no")) {
   write(
@ANSWER1
卖茶姑娘骂道: 我要下班了，要还是不要啦.....
ANSWER1
);
return 1;
}
   if ( arg == "yes" ) {
   write(
@ANSWER2
卖茶姑娘笑道，那我就谢谢你啦，对了，你不是要买减肥茶吗? 我这就送你一份
说完，卖茶姑娘七手八脚的泡了一杯茶给你。
ANSWER2
);
   
   ob1 = new("/d/eastland/liang_shan/obj/diet_tea");
   ob1->move(environment(this_object()));  
   this_player()->set_temp("fat_quest/diet",3);
   this_player()->set_temp("fat_quest/get_tea",1);
return 1;
}
   if ( arg == "no" ) {
   write(
@ANSWER3
卖茶姑娘骂道: 耍我啊，我都快下班了还浪费我时间......说完把珍珠往你头上
丢去，把你打的鲜血淋漓，珍珠也被打坏了。
ANSWER3
);
   return 1;
}
}