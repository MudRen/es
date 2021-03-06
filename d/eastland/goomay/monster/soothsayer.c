#include <mudlib.h>

inherit MONSTER;

void init()
{
	::init();
		add_action( "tip_me", "pay");
        add_action( "ask_me", "ask");
}

int payed;
void create()
{
        ::create();
        set_level( 12 );
	set_name( "soothsayer", "有所不知" );
	add( "id", ({ "man" }) );
        set_short( "有所不知" );
        set_long(
@LONG
    他就是江湖上大名鼎鼎的「无所不知」，一身青衫的他乍看之下就像是
一个落拓的的老学究，只有从他那对微闭著的眼中偶而射出的精光才使你觉
得他的特异，传说中他能够知过去未来，但是他却很少接受江湖人的委托卜
卦，不过，十年前和七年前他对武林大会结果的预测却使人记忆深刻。
LONG
        );
        set( "gender", "male" );
	set("race","human");
	payed=0;
        set( "alignment", 300 );
        set_natural_armor( 70, 25 );
        set_natural_weapon( 21, 10, 20 );
        set_perm_stat( "str", 25 );
        set_perm_stat( "kar", 18 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "dex", 25 );
        set_skill( "dodge", 100 );
        set_skill( "unarmed",100);
        set_skill( "target",60);
        set_skill( "concentrate",60);
        set_skill( "black-magic",60);

        set( "tactic_func", "my_tactic" );
        set ("defense_type","dodge");
        set("spell_levels/black_magic",15);
        set( "spells/ether-bolt",2);
		set("spell_power",0);
        set( "max_sp",500);
        set( "spell_points",500);
        set( "hit_points", 450 );
        set( "max_hp", 450 );
        set( "special_defense", ([ "all": 30 ]) );
        set( "wealth/gold", 20 );
}

int ask_me(string str)
{
        string mon_name,subject;

        if (!str)
                return notify_fail( 
                "要问非玩者人物问题，请用 \"ask <谁> about <关键字>\"。\n");

        if (sscanf(str, "%s about %s", mon_name, subject) != 2)
                return notify_fail(
                "要问非玩者人物问题，请用 \"ask <谁> about <关键字>\"。\n");
        if (mon_name!="soothsayer")
        {
                this_player()->command("ask "+str);
                return 0;
		}
        if (!payed) {
                write(
                "有所不知道：「付一次挂金才能问一个问题 !! 这是规矩 !! 」 \n" );
                return 1;
		}

switch (subject) {
        case "goddess" :
        tell_object(this_player(),
"有所不知点头道：「女神？你是指月神吧 !! 月神是本镇的守护神，数百年前\n"
"这里曾经有一座月神神殿，那真是一幢壮丽美观的宏伟建筑，据说是月神用她\n"
"的神法一夜之间建成的，光是神殿的祭司就有数百人。後来，不知什麽原因，\n"
"神殿突然消失了，於是那些虔诚的祭司和信徒们就在这里定居下来，他们就是\n"
"本镇的开创者。」\n" );
                break;

        case "richman" :
        tell_object(this_player(),
	"有所不知道：「钱不多嘛 !! 他真是个奇特的人，谁也不知道他的来历\n"
    "几年前他突然两手空空的带著老婆来到本镇，短短几年之间他就大发特\n"
	"发起来，也不知道他是怎麽赚钱的，不过别以为他是个典型的暴发户，\n"
	"我觉得他学问顶好，才情不少，而且常常有一些超乎常人的见解，算得\n"
	"上是个奇人。」\n" );
                break;
        case "blacksmith" :
        tell_object(this_player(),
        "有所不知道：「段铁的剑炉是火妖作祟吧 !! 其实这真的也不能怪火妖\n"
	"，天地大道就是如此，火妖因火而生以火为食，当然不能说它错，但是\n"
	"段家又以火为生，如此烦恼纠结，真不是杀戮能够解决的，听说万年冰\n"
	"晶可以克制火妖，不过我想内情并不那麽单纯。段家的前几代也曾经被\n"
	"火妖困扰，最後好像把它困在一个洞里，你可以问问段家的人」\n" );
                break;
        default :
        write(
        "有所不知笑道：「 客官 ... 这种小事你认为很重要吗？你去问路人说不定就可以知道\n"
	"何必要来问我？不过钱还是要照算的 !!\n" );
                break;
}
        payed = 0;
        return 1;
}

int my_tactic()
{
        object victim;
        if( random(20)>6 || !(victim= query_attacker()) ) return 0;
        if( this_object()->query_temp("cast_busy") )
                return 0;
        if( (int)this_player()->query("spell_points") < 100 )
                set( "spell_points",500);
        command("cast ether-bolt at "+(string)victim->query("name"));
}

int tip_me(string arg)
{
        string who, type;
        int num;

        if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
                return notify_fail(
                        "付谁？多少钱？\n");
        if( !id(who ) ) return 0;
        if( type != "gold" ) {
                tell_room( environment(), 
                        "无所不知说道: 客官 ! 对不起，老汉只收金币。\n" ,
                        this_object() );
                return 1;
	}
	if ( num < 10 ) {
	tell_room( environment(), 
                 "无所不知说道: 客官 ! 你想知道的秘密难道只值这些钱吗？\n" ,
                        this_object() );
		return 1;
	}
        tell_room( environment(), 
                 "无所不知点点头道: 客官 ! 你想要问些什麽？运势还是流年？\n" ,
                        this_object() );
	payed=1;

	return 1;
}
