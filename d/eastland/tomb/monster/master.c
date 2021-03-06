#include "../almuhara.h"
 
inherit MONSTER;
 
void create()
{
        ::create();
        seteuid(getuid());
        set_level(19);
        set_name( "The archmaster", "大国师" );
        add ("id", ({ "daemon", "master","archmaster" }) );
        set_short( "大国师  孝光");
        set("unit","位");
        set("exp_reward",40000) ;           
        set("alignment",3100);
        set("wealth/gold",500);
        set_long(
            "大国师  孝光是一位面目和善的人，看起来大约才四十多岁，可是你知道他\n"
            "绝对不只这个年纪。据说他是少数几个从魔族大战中幸存的人，因而来到东\n"
            "方大陆隐居。因为受皇帝的徵召，孝光成了东方王国的国师。他曾拜在龙虎\n"
            "山  张天师的门下，成为天师的得意弟子，因此他精研奇门遁甲、五行土木\n"
            "之学，再加上他本来的知识及能力，使他成为人人敬重的大国师。\n"
        );
        set_perm_stat("str", 25);        
        set_perm_stat("int", 30);
        set_perm_stat("dex", 30);
        set_perm_stat("kar",30);
        set_natural_weapon( 50, 20, 30 );
        set_natural_armor( 100, 50 );
        set_skill("dodge",100);
        
        set ("gender", "male");
        set ("race", "daemon");
        set("max_hp",1500);
        set("hit_points",1500);
        set("time_to_heal",2);
        set("max_sp",2000);
        set("spell_points",2000);
        set( "tactic_func", "my_tactic" ); 
        set("aim_difficulty",(["critical":60,"weakest":60,
                               "vascular":30,"ganglion":60 ])) ;
        set("stun_difficulty/ma",20) ;
        set("unbleeding",1);
        set("special_defense",(["all":70,"none":50,"monk":60,"scholar":60]));
//        set("moving",1);
//        set("speed",30);
//        set("patrol",({"south","sotuh","north","north"}) );
        set( "chat_chance", 10);
        set( "chat_output", ({
        	"大国师深深地看著你，彷佛要看进你的灵魂深处。\n",
        	"大国师缓缓地踱著方步。\n" }) );
	set( "att_chat_output", ({
		"大国师摇摇头说道：为什麽就是有人不爱惜自己的生命呢？\n",
		}) );
        wield_weapon(WEAPONS"/ling");
        equip_armor(ARMORS"/master_hat"); 
        equip_armor(ARMORS"/master_boots");
        equip_armor(ARMORS"/master_robe");
        equip_armor(ARMORS"/master_amulet");
        equip_armor(ARMORS"/master_ring");        
        equip_armor(ARMORS"/shield1");
        set( "inquiry", ([
"almuhara" : ({"他是我最好的朋友。\n" }),
"wiwi" : ({"死包臭包大烂包。\n" }),
"blackjack" : ({"他不坏，他是一个好老头。\n" }),
"monmonpig" : ({"听说他跟阿福有一腿...... :~~~~    我要pk !!\n"}),
"kenwahl" : ({"一个笨巫师，不要理他...\n"}),
"阿福" : ({"问世间情是何物，直叫人生死相\许\........:~~~ \n" }),
"jade" : ({"玉佩？什麽样的玉佩？可否给我看看？\n" }),
"seal" : "@@ask_seal",
"tomb" : ({"你问这干嘛 ?\n" }) ]) );
}
 
void ask_seal(object who)
{
	if ( who->query("quest/sky_guilt") ) {
		tell_object( who, 
		"大国师说道：非常谢谢你的帮忙。\n" );
		return; }
	if ( who->query("sky_guilt") ) {
		tell_object( who,
		"大国师说道：加油!!\n" );
		return; }
        if ( (int)who->query_level() < 17 ) {
                tell_object( who,
                "大国师说道：请珍惜自己的生命，先提升你的能力再说吧。\n" );
                return; }
        if ( who->query("guilt_jade") ) {
                tell_object( who,
                "大国师叹了一口气，说道：『 那封印是用来囚禁人间凶兽 --「天罪」的。\n"
                "多年以前皇上将此剑收入剑冢，我就深深觉得不妥，只恨我当时没有力谏不\n"
                "可，才让它吸取灵气、成了形。虽然我用阵势将其困住，但亦耗了我三分之\n"
                "二的\功\力，已无力将其收服，希望你能替我除此凶兽，并将它带来给我。\n"
                "这儿有一颗九转金丹，应该对你有些帮助。』\n\n" );
                who->delete("sky_guilt");
                new(ITEM"/great_pill")->move(who);
                call_out("give_jade",6,who);
                return; }
        tell_object( who,
                "大国师叹了一口气，说道：『 那封印是用来囚禁人间凶兽 --「天罪」的。\n"
		"多年以前皇上将此剑收入剑冢，我就深深觉得不妥，只恨我当时没有力谏不\n"
		"可，才让它吸取灵气、成了形。虽然我用阵势将其困住，但亦耗了我三分之\n"
		"二的\功\力，已无力将其收服，希望你能替我除此凶兽，并将它带来给我。这\n"
		"儿有一颗九转金丹，应该对你有些帮助。』\n" );
                who->set("sky_guilt", 1);
                new(ITEM"/great_pill")->move(who);
                return;
}
 
void give_jade(object who)
{
        tell_object( who ,
                "大国师说道：对了...差点忘了...上回弄好的赦邪圣玉，正是象徵邪恶与原\n"
                "罪的天罪的天敌，等我为你帮赦邪圣玉开光，以助你诛除天罪凶兽...\n\n"
                "大国师念著一些咒语......\n\n"
                "大国师突然抓住你的手，手中的天师令骤然向你划来，把你吓了一下！\n\n"
                "还好他拿捏得非常准确，仅仅刮去你小指的一小片皮肤，但是鲜血依然不断\n"
                "地渗出....\n\n" );
        who->set_temp("block_command",1);
        tell_object( who,
                "大国师以最快的速度，帮你止血，并用你的鲜血在赦邪圣玉上划下了些你看\n"
                "不懂的符号。\n\n" );
        call_out("tellmethod",12,who);
        return;
}
 
void tellmethod(object who)
{
        command("sweat");
        tell_object( who ,
                "大国师对你说：待与天罪对阵时，用赦邪圣玉丢(throw)向天罪，若能击中\n"
                "那麽天罪的戾气必然大减，你的胜算也会因此提高。祝你凯旋，记得把天罪\n"
                "带来给我...\n\n" );
                new(ITEM"/holy_jade")->move(who);
                who->delete_temp("block_command");
                return;
}
 
void relay_message(string class1, string msg)
{
     string who,aa,str ,str1,str2;
     object *ob,obj,*obj1;
     int i,j;
     
     ::relay_message(class1, msg);
     if( sscanf( msg, "%s(%s)走了过来。\n", aa , who )==2 ) 
       {
         who = lower_case(who);
         obj = find_player(who);
         ob = all_inventory(this_object());
                i = sizeof(ob);
         while(i--) {
                        if( ob[i]->query("equipped") || ob[i]->query("wielded") ) continue;
                      //  if( undefinedp(ob[i]->query("armor_class")) &&
                      //     undefinedp(ob[i]->query("defense_bonus")) )
                      //          continue;
                        ob[i]->remove();
                }
          obj1 = all_inventory(environment(this_object()));
          	j = sizeof(obj1);
          while(j--) {
     		if( present("sky guilt", obj1[j]) ) { 
		        obj = obj1[j];
        	   if( (int)obj->query_temp("GUILT") && 
		        (int)obj->query_quest_level("Sky_guilt") < 1 ) {
      	           obj->finish_quest( "Sky_guilt", 1 );
         		tell_object( obj, 
         		"大国师注视著你身上的『 天罪 』好一阵子。\n"
         		"\n\n"
         		"大国师说道：真是谢谢你的帮忙。我所料的果然不错，在『 天罪 』上本来\n"
         		"镶有一颗具有法力的红宝石，现在却不见了，难怪它能如此嚣张。如果你想\n"
 	       		"驾驭它，必须先找回那颗宝石，将其放入那小洞中，不然恐怕它会伤敌亦伤\n"
 	       		"你喔。\n"
 	        	"\n"
 	        	"你完成了「天罪」任务，得到 20000 经验值。\n");
 			obj->gain_experience(20000);
 			obj->delete_temp("GUILT");
 			return; 
	 		}
	 	}	
         } 
    }
}
int my_tactic()
{ 
    object victim,env;
    int i,j;
 
    env = environment(this_object());       
 
    if( !(victim = query_attacker()) ) return 0;
 
    if( (int)this_object()->query("spell_points") < 500 )
      this_object()->set("spell_points", 2000);
    
    if( ((int)this_object()->query("hit_points") < 200) && random(10) > 7 ) {
	tell_room(env,
		"\n"+"你看到大国师招出水之精灵帮他治疗伤口。\n",this_object() );    	
      	this_object()->add("hit_points", 200); 
      	return 1; }
    
    i = 30 - (int)victim->query_perm_stat("int") ;
    j = 30 - (int)victim->query_perm_stat("kar") ;
    
    if ( random(50) < i+j  )
       { 
          if(random(5) < 2) {
          	if ( (int)this_object()->query("hit_points") < 200 ) { 
          	tell_room( env, 
          		"\n"+"大国师将自己所受到的攻击转到"+victim->query("c_name")+"身上。\n",
          		({victim,this_object()}) );	
		tell_object( victim, 
			"\n"+"大国师将自己所受到的攻击转到你身上。\n");          
		this_object()->receive_healing(60);
		victim->receive_damage(random(50));  
		return 1;
                	}
                else return 0;
                }
          else 
		tell_room( env, 
			"\n\n"+"大国师大喊：「 五雷天心正法 」!!\n"+"\n\n" 
			, this_object() );
		victim->receive_special_damage("electric",80);  
          return 1 ;
        }
    else 
          return 0 ;
 
}
void die()
{
  int i ;
  object scroll,killer,*player ;
 
  player = users() ;
  killer = query("last_attacker") ;
  scroll = new("/d/mage/tower/obj/ltn4_scroll") ;
  scroll->move(environment(this_object())) ;
 
  for(i=0;i<sizeof(player);i++)
    {
  tell_object(player[i],"\n震动的大地传出大国师 孝光低沉的悲叹 : \n
  天亡吾也，非战之罪啊!!! \n");
     }
 
  ::die(1) ;
}
int accept_item(object who,object item )
{
    if( (item->query("sky_guilt_jade1")) )
      {
        who->set_temp("ask_jade",1);
        tell_object(who,@MSG
大国师仔细端详这块玉佩......
大国师将玉佩拿近七彩石，七彩石竟和玉佩同时发出强光，照得你目眩神摇。
 
大国师眼中闪著兴奋的光芒。
大国师对你说道：这是我叫我弟子外出寻找的赦邪圣玉的一部份，上回他已经差人
　　　　　　　　把另一半送回来了，收在我老婆那儿，麻烦你去跟我老婆拿另一
　　　　　　　　块好吗？
MSG );
      }
    if( (item->query("sky_guilt_jade2")) )
      {
        if (who->query_temp("ask_jade")) {
        tell_object(who,@MSG
大国师仔细端详这块玉佩......
 
大国师将手中的两块玉佩依著断口接合，一道银白免的光茫由玉佩中泛出，使你感
到一阵暖意......
 
大国师面带微笑地对你说：谢谢...这样一来就算解除封印也无所谓了....
MSG );
who->set("guilt_jade",1);
} else {
        tell_object(who,@MSG
大国师仔细端详这块玉佩......
 
大国师对你说：你这块玉佩是那里偷来的？不要耍我......
MSG ); }
      }
item->remove();
tell_object(who,"谢谢你......\n");
return 0;
}
