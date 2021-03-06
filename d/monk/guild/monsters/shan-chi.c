#include <mudlib.h>
#include <ansi.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "Shan chi", "玄慈神僧" );
        add ("id", ({ "monk","shan","chi" }) );
        set_short( "Shan chi","玄慈神僧");
        set("unit","位");
        set_long("",@C_LONG
玄慈是少林寺仅存数位玄字辈的长老之一，也是前两任的方丈。他年
轻的时候喜欢习武，所练就的九阳神功和易筋经至今仍然傲视武林。但是
他现在已经不问世事了，除了偶尔少林寺遇到重大变故的时候会出面解危
以外，平时都负责指导少林公会。
C_LONG
        );
        set("exp_reward",50000);
        set("alignment",2000);
        set("wealth/silver",100);
        set("gender","male");
        set("race","human");
        set("tactic_func","special_attack");
        set("hit_points",2000);
        set("force_points",2500);
        set("max_hp",2000);
        set("max_fp",2500);
        set_perm_stat("str",30);
        set_perm_stat("dex",26);
        set_perm_stat("pie",30);
        set_perm_stat("kar",24);
        set_perm_stat("con",29);
        set_perm_stat("int",25);
        set_natural_weapon(35, 14, 30);
        set_natural_armor(90, 30);
        set_skill("dodge",100);
        set_skill("blunt",100);
        set_skill("parry",100);
        set_skill("inner-force",100);
        set("attack_skill","monk/general/king_kong");
        set("monk_gonfu/king-kong",35);
        wield_weapon("/d/monk/guild/weapons/kingkong_staff");
        equip_armor("/d/monk/guild/armors/sandal_beads");
        equip_armor("/d/monk/guild/armors/damo_plate");
        equip_armor("/d/monk/guild/armors/god_armband");
        equip_armor("/d/monk/guild/armors/holy_ring");
        equip_armor("/d/monk/guild/armors/cloud_boots");
        set("inquiry", ([
        "brassman" : "@@ask_brassman",
        "还俗" : "@@ask_return",
        "证明" : "@@ask_proof",
        "金刚杖法" : "@@ask_staff" ]) );
}

int ask_staff()
{
   int gonfus,check_book_quest;
   object me;
   
   me = this_player();
   gonfus = 0;
   check_book_quest = me->query("book_quest_finish");

   if( !check_book_quest ) {
      tell_object( me, "\n玄慈忧心地说道：唉！失去的楞枷经尚未寻回，目前我实在是难以静下心来好好地传授你武功\！\n");
      return 1;            }

   if( me->query("monk_gonfu/king-kong") ) {
      tell_object( me, "\n玄慈说道：你不是已经学过了吗？该要好好练习才是....\n");
      return 1; }

   if( me->query("monk_gonfu/body-def") == 35 ) gonfus++;
   if( me->query("monk_gonfu/bolo-fist") == 35 ) gonfus++;
   if( me->query("monk_gonfu/dragon-claw") == 35 ) gonfus++;
   if( me->query("monk_gonfu/keep-flower") == 35 ) gonfus++;
   if( me->query("monk_gonfu/power-finger") == 35 ) gonfus++;
   
   if( wizardp(me) )
      printf("\nNumber of top 72 gonfus ： %d\n",gonfus);

   if( gonfus < 2 )
      tell_object( me, "\n玄慈温和地说道：想要学好武器, 就先把拳脚练好再来吧...\n");
   else {
      tell_object( me, @MSG

玄慈和蔼地摸摸你的头.

玄慈说道：难得！难得！如此勤练功夫，你的确是有资格练金刚杖法。
          来！就让我演练一次给你看吧！
          
玄慈缓缓地将金刚杖举起，双眼流露出恢弘的气势......

突然！玄慈连续使出金刚杖法中的招式，只见一道灰影在空中翻腾,
时见一道道的金光透影而出, 威猛无涛......

不一时, 灰影逐渐清晰, 慢慢看出玄慈的容貌....

玄慈笑笑地对你说：好孩儿！了解了吗？

你点了点头.

玄慈和蔼地摸摸你的头说道：金刚杖法，威猛无涛，使用时要心存善念才好啊！

MSG );
      me->set("monk_gonfu/king-kong",0); }

  return 1;

}

int special_attack()
{
    object victim;
    int fp;
    
    if(random(20)>7) return 0;
    victim = query_attacker();
    if( !victim ) return 0;
    fp=(int)victim->query("force_points");
    tell_room(environment(victim),
"\n玄慈运起九阳神功，一道浑厚的内力自丹田涌向双手，向"+
(string)victim->query("c_name")+"直冲而去。\n",victim
	);
    tell_object(victim,@C_LONG
    
玄慈运起九阳神功，霎时你被一股强大的内力笼罩著。突然这股劲力直冲
你的丹田，你觉得你的经脉似乎已经断了。

C_LONG
    );
    victim->receive_damage(60-random(fp/10));
    return 1;
}

int ask_brassman()
{
	object obj;
	obj = this_player();
	
	if( !obj->query("18brass") ) {
		tell_object(obj,
			"玄慈 长老说道：有关铜人阵的事情，你可以去请教慧元师侄。\n" );
		return 1; }
	if( (int)obj->query("18brass") == 1) {
		tell_object(obj,
			"玄慈 长老说道：你已通过铜人阵了。那麽现在你想( 还俗 )或是得到一项\n"
			"	       ( 证明 )呢 ?\n" );
		return 1; }
}

int ask_return() 
{
	int i;
	object obj,*urs;
	string c_msg;
	
	obj = this_player();
	urs = users();
	
	if( !obj->query("18brass") ) {	
		tell_object(obj,
			"玄慈 长老说道：请先通过铜人阵再说吧。\n" );
		return 1; }
	if( (int)obj->query("18brass") == 1) {
		tell_object(obj,
			"玄慈 长老看了你一会儿.............\n\n\n"
			"突然一巴掌在你的光头上打了一下 !!\n"
			"玄慈 长老说道：阿弥陀佛，尔今日再度坠入红尘，受那三千烦恼之苦，\n"
			"	       罢了罢了.....\n" );
	c_msg = set_color("[少林和尚] 玄慈 神僧: ","HIC");
		c_msg += "今日 "+obj->query("c_name")+"("+obj->query("name")+") "+
		  "成为少林俗家弟子 !!\n";
	for( i=0; i<sizeof(urs); i++ )
		if( (string)urs[i]->query("class") == "monk" )
			urs[i]->quick_message(c_msg); 
	obj->add("18brass",1); 
	return 1; } 
	return 0;
}		
		
int ask_proof() 
{	
	int i;
	object obj,*urs;
	string c_msg;
	
	obj = this_player();
	urs = users();
	
	if( !obj->query("18brass") ) {	
		tell_object(obj,
			"玄慈 长老说道：请先通过铜人阵再说吧。\n" );
		return 1; }
	if( (int)obj->query("18brass") == 1) {
		tell_object(obj,
			"玄慈 长老微笑著说道：恭禧你通过了十八铜人阵，这个臂环就是你通过\n"
			"	             考验的证明 !!\n" );
		new("/d/eastland/saulin_temple/brass/obj/armband")->move(obj);
	c_msg = set_color("[少林和尚] 玄慈 神僧: ","HIC");
		c_msg += "恭禧 "+obj->query("c_name")+"("+obj->query("name")+") "+
		  "通过十八铜人阵的考验 !!\n";
	for( i=0; i<sizeof(urs); i++ )
		if( (string)urs[i]->query("class") == "monk" )
			urs[i]->quick_message(c_msg); 
	obj->add("18brass",2); 
	return 1; } 
	return 0;	
}	
