 // chi_yu_group.c ������ȵ������ǹ�ͬinherit �ĵ�

#include <mudlib.h>
#include <conditions.h>
#define HEADQUARTER "/d/eastland/liang_shan/daemons/chiyu_army_d"

inherit MONSTER;

void create()
{
	::create();
	HEADQUARTER->add_member();
}
void heal_chi(int heal)
{
        receive_healing( heal );
}        
void relay_message(string class, string str)
{
        int i,hitp,hp1,hp2;
        string name,direction,tmp,guild;
        object victim,mob,env,*who,bandage;
        mixed bandaged,bleed;
        ::relay_message(class,str);
        
        
        if( !str || str == "" ) return;
        if( sscanf(str,"%s(%s)���˹�����", tmp,name)==2 ) {
        name = lower_case(name);
        victim = present(name, environment(this_object()));
        if( !victim || victim->query("npc") || victim->query("no_attack")) return ;
        
        if( victim->query_level() > 5 && !victim->query("ghost") && victim->query("alignment") >100 ) {  
        
        if( !pointerp(attackers) || member_array(victim, attackers)==-1 ) {
        
        tell_object(victim,query("c_name")+"�е� : ͨͨȥ���ɣ�ͬʱ���������������������....\n");
         kill_ob(victim);
         } } }
        
        
        if( sscanf(str,"%s(%s)��%s���뿪��", tmp,name,direction)==3) {
        name = lower_case(name); 
        victim = find_living(name);
        guild = victim->query("class");
           
           
           if  ( query("c_name") == "���" ) {
           if  (wizardp(victim)) return ;
           tell_object( victim, set_color(
           "\n ���ԶԶ�Ķ���ӻ��֣���������Щ��ֵ����ģ�ͻȻһ�������Χ���㣬��о���һ\n"
           "���ݵ�����ݷ��뿪��������壬ͬʱ������е㲻���.......\n\n" , "HIY",this_object()) ); 
           
//����Ƿ񱻳���������򲻻��ٽг�ͬ���Ĺ���           
           
           if ( !victim->query_temp("be_caught") ) {
           mob = new("/d/eastland/liang_shan/monster/evil_"+guild);          
           mob->move(environment(this_object()));
           mob->set("name",name);
           mob->add("c_name", victim->query("c_name"));
           mob->set_level(victim->query_level()-1);
           mob->set_perm_stat( "str", victim->query_perm_stat("str") );
           mob->set_perm_stat( "dex", victim->query_perm_stat("dex") );
           mob->set_perm_stat( "kar", victim->query_perm_stat("kar") );
           mob->set_perm_stat( "pie", victim->query_perm_stat("pie") );
           victim->set_temp("be_caught",1);
           victim->add("alignment",1000);
           }

//�����������ͳ�а���Ӱ
           
           if ( random(5) < 1 ) {
           mob = new("/d/deathland/monster/evilshadow"); 
           mob->move(environment(this_object()));
           }
         }
          if  ( query("c_name") == "������ҽ" ) {
          if ( query_attacker() ) return ; 
          env = environment(this_object());
          who = all_inventory(env);
          for( i=sizeof(who)-1; i>=0; i-- ) {
          
          if ( !who[i]->query("chi_yu_group") ) return ;

         if ( bleed = who[i]->query("conditions/bleeding") ) {
         if (this_player()->query_temp("clotted")==0) {
         if( 50 + random(50) > bleed[1] * bleed[2] ) {
         (CONDITION_PREFIX + "bleeding")->remove_effect( who[i]);
         } else {
         bleed[2] /= 2;
         who[i]->set( "conditions/bleeding", bleed );
          }
         tell_room(environment(this_object()),set_color(
         "\n������ҽ����ս����һ���䣬�ܿ�Ķ�"+who[i]->query("c_name")+
         "����ֹѪ��\n\n","HIY",who[i]),who[i]);
         who[i]->set_temp("clotted", 1 );
         call_out( "remove_clotted", 45, who[i] );
        } }
          
          hitp = who[i]->query("hit_points");
          hp1 = who[i]->query("max_hp")/2;
          hp2 = who[i]->query("max_hp")/4;
     
     if (hitp < hp2 ) {
          
          if (who[i]->query_temp("aided")==0) {
             who[i]->receive_healing(60+random(25));
             who[i]->set_temp("aided",1);
             call_out("can_aid_again",180,who[i]);
             tell_room(environment(this_object()),set_color(
             "\n������ҽ����ս����һ���䣬�ܿ�Ķ�"+who[i]->query("c_name")+
             "���м��ȡ�\n\n","HIY",who[i]),who[i]);
              }}
         
         if (hitp < hp1)  {
        
          if (!bandaged = query("conditions/bandaged")) {
         
          tell_room(environment(this_object()),set_color(
          "\n������ҽ�ӻ����ͳ�һЩҩ�࣬�ܿ��Ĩ��"+who[i]->query("c_name")+
          "�˿��ϡ�\n\n","HIY",who[i]),who[i]);
          HERB_APPLY->apply_effect(this_player(), 8, 5, 30);
          bandage = new("/obj/bandage");
          bandage->move(this_object());
          command("bandage "+who[i]->query("name"));         
          }}
          continue ;
}}}}
void remove()
{
	HEADQUARTER->remove_member();
	return ::remove();
}

int stop_attack()
{
	HEADQUARTER->add_huntee(this_player());
	return 0;
}

void pseudo_hunt(object me, object player)
{
	if( environment() && present(player, environment()) ) 
		if( this_object()==me )
			tell_room( environment(), 
				query("c_name") + "���������ͼ�����: �ֵ��ǣ��������һ���������ˣ�\n",
				this_object() );
		else {
			tell_room( environment(), 
				query("c_name") + "ͻȻ��������ǰ����ʼ����������\n",
				this_object() );
			if( !pointerp(attackers) || member_array(player, attackers)==-1 )
				kill_ob(player);
		}
	else if( !pointerp(will_attack) )
		will_attack = ({ player });
	else if( member_array(player, will_attack)==-1 )
		will_attack += ({ player });
}
