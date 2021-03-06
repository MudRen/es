#include <mudlib.h>

#define PETDIR "/d/noden/farwind/pet/pet_"

inherit ROOM;

#define PRICE ({ 0, 1500, 2000, 1400, 1400, 1800, 3500 })
#define PETS ({ "none", "cat", "dog", "bird", "rat", "pig", "dino" })
#define AMOUNT ({ 0, 4, 4, 5, 5, 3, 2, })
void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "茹比宠物专卖店" );
        set_long(@LONG
这里是一家宠物店，一进门就听到满屋子的宠物叫声，你可以随意看看或跟
一些比较乖的宠物玩，如果真的很喜欢，你可以参考墙上的价目表(menu)再决定
要不要带它回家，你可以在这里买卖宠物，同时他们也会帮你找回(looking)失踪
的宠物。
LONG
        );

        set("item_func",(["menu": "msg_menu", ]));
        set("exits", ([
            "south" : "/d/noden/farwind/bazz3",
        ]) );
        set( "amount", AMOUNT );
        reset();
}

void init()
{
		add_action( "call_pet", "looking");
        add_action( "buy_pet", "buy");
        add_action( "sell_pet", "sell");
}

int msg_menu()
{
	int *amount;
	amount = this_object()->query("amount");

write(
"墙上挂著一张可爱的宠物月历，上面注明著每种宠物的特性和价钱 ：\n\n"
"                      茹比宠物专卖店\n"
"    ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n"
"    ＝  喵喵猫  (pet cat)     "+PRICE[1]+" 银币    还有 "+amount[1]+" 只  ＝\n"
"    ＝  大笨狗  (pet dog)     "+PRICE[2]+" 银币    还有 "+amount[2]+" 只  ＝\n"
"    ＝  精灵鸟  (pet bird)    "+PRICE[3]+" 银币    还有 "+amount[3]+" 只  ＝\n"
"    ＝  天竺鼠  (pet rat)     "+PRICE[4]+" 银币    还有 "+amount[4]+" 只  ＝\n"
"    ＝  迷你猪  (mini pig)    "+PRICE[5]+" 银币    还有 "+amount[5]+" 只  ＝\n"
"    ＝  小火龙  (mini dino)   "+PRICE[6]+" 银币    还有 "+amount[6]+" 只  ＝\n"
"    ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n\n"+
"ＰＳ：本店以市价的一半收购您不要的宠物，请不要让你的宠物走失。\n"
	);
	return 1;
}
int call_pet()
{
 	object ob;
 		
 	ob = this_player()->query_temp("now_pet");
	if( !ob )
		return notify_fail("店员摇摇头说：你又没有宠物.\n");
	if( present(ob, this_object())	) {
		tell_object( this_player(),
            "店员说道: 你的宠物已经在这里, 不用去找了!\n" );
        return 1;
	}
	tell_object(this_player(),
		"店员拿出一把哨子，用力一吹，哔～～的一大声，差点没把你的耳朵震聋 .\n"
		"突然你的宠物不知道从哪里钻了出来，在你的四周高兴地跑来跑去。\n"
		);
	ob->move_player(this_object(),"SNEAK");	
	return 1;
}

int sell_pet(string arg)
{
 	object ob;
 	int i=0, *amount;
 	if( !arg || arg != "pet" )
 		return notify_fail("指令格式 : sell pet (如果你有).\n");
 		
 	ob = this_player()->query_temp("now_pet");
	if( !ob )
		return notify_fail("你没有宠物.\n");
	if( !present(ob, this_object())	) {
		tell_object( this_player(),
            "店员说道: 对不起，你的宠物不在这里, 快去把它找回来吧!\n" );
        return 1;
	}

	switch( (string)ob->query("pet_type") ) {
        case "cat"  : i=1;  break;
        case "dog"  : i=2;  break;
        case "bird" : i=3;  break;
        case "rat"  : i=4;  break;
        case "pig"  : i=5;  break;
        case "dino" : i=6;  break;
        default :
          tell_object( this_player(), 
            "店员说道: 对不起，本店不收购这种宠物。\n" );
          return 1;
    }

	if( i<1 || i>6 ) return 0;
	
    this_player()->credit("silver", PRICE[i]/2);
    this_player()->set_temp("now_pet", 0);
    ob->remove();
    amount = this_object()->query("amount");
    amount[i]++;
    this_object()->set("amount", amount);
    tell_object(this_player(), 
        "你卖掉你的宠物，得到 "+(PRICE[i]/2)+" 块银币。\n"
		);
    return 1;
}

int buy_pet(string arg)
{
	object ob;
	int i=0, *amount;

	if( !arg || arg == "" )
		return notify_fail("指令格式 : buy <宠物名称>.\n");
	
	if( this_player()->query_temp("now_pet") )
    	return notify_fail("对不起, 一个人只能有一只宠物。\n");
          
	amount = this_object()->query("amount");
	if( !amount )
		return notify_fail("对不起, 本店所有的宠物都已卖完了。\n");
          
	switch (arg) {
        case "cat"  : i=1;  break;
        case "dog"  : i=2;  break;
        case "bird" : i=3;  break;
        case "rat"  : i=4;  break;
        case "pig"  : i=5;  break;
        case "dino" : i=6;  break;
        default :
          tell_object( this_player(), 
            "店员说道: 对不起，本店没有卖 "+arg+" 这种宠物。\n" );
          return 1;
          break;
    }
    if( i<1 || 1>6 ) return 0;
    if( amount[i] < 1 ) {
    	tell_object( this_player(), 
          "店员说道: 对不起，本店 "+arg+" 这种宠物已经卖完了。\n" );
        return 1;
    }
    
    if( !this_player()->debit("silver",PRICE[i] ) )
        return notify_fail("你没有那麽多银币。\n");

	amount[i]--;
	this_object()->set("amount", amount);
    ob = new( PETDIR+PETS[i] );
    ob->move( this_object() );
    
    this_player()->set_temp("now_pet", ob);
    ob->set_master( this_player() );

    tell_object(this_player(), 
        "店员把你的宠物交给你，笑道：「你要好好照顾它喔 !!」\n");
    return 1;
}

void add_amount(string type)
{
	int i=0, *amount;
	
	if( !type || type == "" ) return;
	switch (type) {
        case "cat"  : i=1;  break;
        case "dog"  : i=2;  break;
        case "bird" : i=3;  break;
        case "rat"  : i=4;  break;
        case "pig"  : i=5;  break;
        case "dino" : i=6;  break;
        default : return;
    }
    if( i<1 || i>6 ) return;
    amount = this_object()->query("amount");
    amount[i]++;
    this_object()->set("amount", amount);
}

void reset()
{
	set("amount", AMOUNT );
	::reset();
}
