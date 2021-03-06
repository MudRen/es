
inherit "/std/pet.c" ;

void init()
{
	::init();
    add_action("order_me","order_cat");
    add_action("help_order", "help");
}

void create()
{
        ::create();
        set_level(1);
        set_name("pet cat","喵喵猫");
        add( "id", ({ "cat","pet" }) );
        set_short( "迷途的喵喵猫");
        set_long(
@C_LONG
这只猫是某人的宠物，它喜欢跟著主人走来走去。它现在正用它那对美丽的
蓝眼睛好奇地看著你。它的脖子上挂著一块牌子，上面写著：
        －－－－－－－－－－－－－－－－－－－－－－－
              我是乖猫咪，请不要随便把我丢在路边
        －－－－－－－－－－－－－－－－－－－－－－－
如果你是它的主人，你可以用 order_cat <commands> 让它听话。
C_LONG
        );
        set_perm_stat("str", 2);
        set_perm_stat("con", 2);
        set_perm_stat("dex", 2);
        set_perm_stat("int", 2);
        set_perm_stat("pie", 1);
        set_perm_stat("kar", 1);
        set_temp("effect/power-boost", 1);
        set("max_load", 75);
        set("weight", 100);
	set("post_name","'s pet cat");
        set("c_post_name","的喵喵猫");
        set("prevent_give_money", 1);
        set("pet_type", "cat");
        set("tactic_func", "call_help");
        set_c_verbs( ({ "%s张嘴往%s一咬", "%s用它的爪子抓%s" }) );
        set ("chat_chance",5);
        set ("chat_output",({
        "猫咪喵喵叫了几声，在你的脚边挨挨擦擦的走来走去。\n",
        "猫咪拱起了背，伸伸懒腰，开始用爪子洗脸。\n"
        }));
        setenv("C_MMIN","$N用优雅慵懒的步子走了过来。");
        setenv("C_MMOUT","$N用优雅慵懒的步子走开。");
}
