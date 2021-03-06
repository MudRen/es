#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Master Tenshin", "天心大师" );
	add( "id", ({ "monk", "tenshin", "master", }) );
	set_short( "天心大师" );
	set_long(
@LONG_DESC
你看到一位慈眉善目的老和尚，他就是药王殿的长老－天心大师，大师年纪已经
很老了，可是由於养生有道，体力仍然不减。他最大的乐趣就是钻研医药以济世
救人，也由於他精通经脉气血之道，大师的点穴功\夫冠绝少林，有时候连方丈都
会来向他请益。他现在正在清点药草(herb)的数目。
LONG_DESC
	);
    set( "inquiry", ([
         "herb" : 
@HERB
阿弥陀佛! 施主有所不知，近日天候异常，药圃中的回阳草竟
              然乾枯\殆尽，回阳草是炮制九转回阳膏的必需药物，又是极有
              用的救急续命药，实在是一日不可或缺，老纳心急如焚偏又病
              患如潮，实在没有时间去寻它，记得当时老纳曾在後山试植一
              株，不知现下如何了？可否请施主前往一探，倘若侥幸存活，
              麻烦施主将它移回药圃，敝寺上下同感大德! 阿弥陀佛...
HERB
	     ,
	"heal" : "@@ask_heal",
]));
	set("race", "human");
	set("gender", "male");
	set_perm_stat("int", 30);
	set_perm_stat("str", 25);
	set_perm_stat("dex", 30);
	set_skill("dodge", 100);
	set_skill("dagger", 100);
	set_skill("anatomlogy", 100);
	set("aiming_loc", "weakest");
	set("max_hp", 987);
	set("max_fp", 543);
	set("force_points", 543);
	set("hit_points", 987);
	set_natural_armor( 50, 40 );
	set_natural_weapon( 5, 15, 25 );
	set("special_defense", ([ "all": 50, "none":30 ]) );
	set("aim_difficulty", ([ "critical" : 50, "vascular" : 50, ]) );
	set("alignment", 1500);
	wield_weapon( SAULIN_OBJ"holy_dagger2" );
	equip_armor( SAULIN_OBJ"cloth2" );
	equip_armor( SAULIN_OBJ"boot2" );
}

void init()
{
	::init();
	add_action("report_master","report");
}

int tired(object who)
{
        tell_room( environment(), 
        "天心大师从运功\中醒来，看起来精气十足 !!\n" ,
        this_object() );
        set("tired",0);
        return 1;
}

int check_tired()
{
        if ((int)this_object()->query("tired")==1)
        {
        tell_room( environment(), 
        "天心大师正在运功\，你最好别吵他 !!\n" ,
        this_object() );
        return 0;
	}
        return 1;
}

int I_hate_killer()
{
        if ( this_player() == query_attacker() || (this_player()->query_temp("saulin_killer")) ) 
        {
        tell_room( environment(), 
        "天心大师合十道: 施主满手血腥，请及早回头，恕老僧不能助纣为虐 !!\n",
        this_object() );
        return 1;
	}
        return 0;
}
int check_quest()
{
        if (this_player()->query("quest/Tenshin's_herb"))
        return 1;
        tell_room( environment(), 
		"天心大师合十道：「不是老僧不肯帮你，而是老僧有是在身 !! 请施主见谅 !」\n"
	,this_object() );
        return 0;
}
int ask_heal()
{
	int num,hpmax,hp;

        if (!check_tired()) return 1;
        if (query("hit_points") < query("max_hp"))
        {
        tell_room( environment(), 
        "天心大师笑道: 咦？老僧什麽时候受的伤？赶快疗伤 !! ... \n"
        "他坐下来开始运功\疗伤。\n",
        this_object() );
        set("hit_points",query("max_hp"));
        set("tired",1);
        call_out("tired", 300+random(90),this_object());
        return 1;
	}
        if (I_hate_killer()) return 1;
        if (!check_quest()) return 1;
        command("look "+(string)this_player()->query("name"));
        hpmax=this_player()->query("max_hp");
        hp=this_player()->query("hit_points");
        if (hpmax==hp)
        {
        tell_room( environment(), 
        "天心大师笑道: 可是施主您很健康啊 ... \n" ,
        this_object() );
        return 1;
	}
        num=(hpmax-hp)*2;
       if( !this_player()->debit("gold", num) )
        return notify_fail(
        "你突然想起身上没带足够的香油钱... 不好意思开口请大师医疗\n");

        tell_room( environment(), 
        "天心大师说道：「好 !! 请施主安心 !」他的双手搭在你的背心，你突然感到\n"
        "两道强劲的真气开始环绕全身，刹时你觉得全身说不出的舒畅。\n"
	"他笑咪咪的看著你，然後头一点，咦 ？ 入定了 ？？\n" ,
        this_object() );
        this_player()->set("hit_points",hpmax);
	tell_object(this_player(),
	"为了感谢大师的辛劳，你很诚心的捐了些香油钱。\n" );
        set("tired",1);
        call_out("tired", 300+random(90),this_object());
        return 1;

}

int report_master(string arg)
{
	string who, type;
	
    if( !arg || (sscanf(arg, "%s to %s", type, who) != 2) )
    	return notify_fail( 
    	  "回报什麽事给(to)谁？\n" );
    if( !id(who) )
    	return notify_fail(
    	  "你要向谁报告啊! 这里没这个人\n" );

	if( type=="herb" ) {
        tell_object( this_player(), @REPORT
        
天心大师说: 阿弥陀佛! 善哉善哉! 施主此举真乃是造福万民，敝寺倘有济世
            微名全赖施主之功\。只是老纳有一事不明，回阳草生长迅速，何
            以在数日之间枯\死殆尽？又药圃中之水井又何以一夜间乾涸见底
            ？种种疑问令人不解，施主有兴可否前往一探(explore)？
			
REPORT
        );
	return 1;
	}
	if( type=="mushroom" ) {
		tell_object( this_player(),@MUSHROOM
		
天心大师说: 阿弥陀佛! 善哉善哉! 原来如此，自来灵山自有灵物，灵芝家
            族能择少林而居，难道我等竟不舍一井之水吗？更何况上天有
            好生之德，且让它们安居於此吧! 灌溉之水老纳再另想办法就
            是了 !! 多谢施主辛苦 !! 日後施主若有需要医疗(heal)老僧
	    愿效绵薄之力。
			
MUSHROOM
        );
		return 1;
	}
	return 1;
}

