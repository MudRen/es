#include "/d/eastland/story/story.h"
int time=0,k=0;
string *cast_msg1=
     ({ "%s��ʼ���ۿ����к������������۳�һ�ɾ޴�ı��ţ�\n",
        "%s���п�ʼð������İ��̣����Щ΢����!\n",
        "%s���ϵ��������������΢������â�� \n" }),
       *cast_msg2=
     ({ "%s���Եı��ż��ٵ���������ǰ���ݷ���֫�ٺ���Ҫ�������ˣ�\n",
        "%s���д󺰡�������𡹣����������������Ͻ�ȥ��ʹ����ʹ�ѵ�!\n",
        "ֻ��%s���е���â�䴩���㱰΢������!\n" }) ;
inherit MONSTER;
void create()
{
	::create();
	set_level(18);
	set_name( "Archmaster Chn.", "����" );
	add ("id", ({ "archmaster","master","chn","chn."}) );
	set_short( "����ʦ ����");
	set_long(@CLONG
����ʦ ���� �ǳ��ڽ���춳�����Ȩλ��ߵ��ˣ�ƽʱֻ����춳�������˵�ǡ�һ
��֮�£�����֮�ϡ��������ٳ����һ��������Լ������ʮ����ͣ�һ����ò��
Ȼ���Ͱ����ף���üҵ�Ѵ������£������κν���֮����ٲȻ��λ�������ߡ�����
ͬʱ�ǳ��м�ʶ��࣬������Ϊ�ḻ���ˣ�ƽʱ��������ԥ���������鶼��������
��̣�����������ǻ�����飬��ˣ�����Ϊ������õ������֡��������ó����
�߽���֮�࣬���ӽ����ϣ�ħ�������Ǹ�ǿ�������ħ�������������е����֮��
����һ�����������ʲ������ħ��������֮��(wand)�����Ż�����������ֽ̡�
CLONG
	);
	set("gender","male");
        set("race","��ʦ");
	set_perm_stat("str", 18 );
        set_perm_stat("dex", 25 );
        set_perm_stat("kar", 25 );
        set_perm_stat("int", 30 );
	set( "alignment", 1000 );
	set( "hit_points", 750 );
	set( "max_hp", 750 );
        set( "max_fp",350);
	set( "force_points",350);
	set_natural_weapon( 22, 8, 18 );
	set_natural_armor( 45, 30 );
        set("aim_difficulty",([ 
    	  "critical":80,"vascular":40,"weakest":40 ]) );
        set("wealth/gold",100);
        set("stun_difficulty",100);
        set_temp("bs",20);
        set_temp("be_joke",3);
        set_skill("dodge",90);
        set_skill("parry",90);
        set_skill("wand",70);
        set("tactic_func","my_tactic");
        wield_weapon(SWWEA"wiz_wand1");
        equip_armor(SWARM"wiz_robe1");
        equip_armor(SWARM"wiz_ring1");
        equip_armor(SWARM"wiz_amulet1");
        set("special_defense",(["all":100,"none":40,"cold":70,"monk":30]));
        set("inquiry",([
          "special_things":"@@ask_things",
         "entrance_palace":"@@ask_entrance", 
                    "help":"@@ask_help",
            "golden_older":"@@ask_older",
            "fly_building":"@@ask_building",
           "great_vampire":"@@ask_vampire",
             "spirit_ball":"@@ask_ball",
            "heaven_water":"@@ask_water",
                    "wand":"@@ask_wand",
                     "fix":"@@ask_fix"
        ]) );  
}
int convert_value(object ob)
{
    mixed *charge;
    int val;
    charge = ob->query( "value" );
    if( !charge || !pointerp(charge) ) 
        return 2000;
    if( !intp(charge[0]) || charge[0]==0 || !stringp(charge[1]) ) 
        return 2000;
    val = charge[0] * coinvalue( charge[1] ) / coinvalue("silver");
    if( val < 1000 ) val = 2000;
    return val;
}
void ask_fix(object asker)
{
    object wea1;
    string name;
    int value;
    wea1=asker->query("weapon1");
    if (!wea1 || (wea1->query("type")!="wand") ) {
       write("����˵���������ϲ�û���κ�ħ���������ɹ�������\n");
       return ;
    }
    if ( wea1->query("charge_left") ) {
       write("����ҡҡͷ�������ҵ��������������ħ����������û�л�����\n");   
       return ;  
    }
    value=convert_value(wea1);
    name = wea1->query("c_name");
    if ( !asker->debit("silver", value/2) ) {
       write(sprintf("����˵�����Բ���Ҫ�޸���� %s ��Ҫ %d �����ң�\n"
            ,name,value/2));
       return ;
    }
    wea1->unwield();
    write(sprintf("\nֻ�����������дʣ�Ȼ��һ����ɫ�Ĺ�â�����������ϵ� %s ..\n\n",name));
    wea1->create();
    write(sprintf("����˵�������ˣ���ȡ�� %d �����Ҳ��������� %s �޸���ϣ������Կ���\n\n",value/2,name));
    return ;
}                             
              
void ask_wand(object asker)
{
write(@LONG
����˵�������ǿ��԰�������(fix)ĳЩ�����ħ���������������������ȡ��
�����������ɷ��á�
LONG
   );
}
void ask_water(object asker)
{
write(@LONG
����˵��������֮ˮ����˵�е�����֮ˮλ춼�������ش�����������ǻ���
�����������Ǽ���ȡ�õġ�����֮ˮ���������Ǵ������״̬������ô�����
�����������������֮�࣬���Ǽ���̩�곣���Ĵ���«����ԭ��������ʢ��
�����������������ߡ������̩���ǲ��������˵����ĺ�«�ģ���һ����
����������װ����װ��֪����    

LONG
   );
}

void ask_ball(object asker)
{
write(@LONG
����˵�����������项���ǳ������������ҵ���
�����������������项ԭ���ǳ�����������һ��ɱ����������������е�����
������������ҩ֮��ģ�������������������ڵĶ�ҩ���������˵�ѪҺ����
���������������࣬������������һ����ԭ���Ǽ�����Ķ������Թ�����ֻ��
          �������������˱��ܣ��޹ֺ�������������ţ���һ�䵽���˵���
          �У��ǽ���һ��ƽ١�����ˮ�ܸ����������ۣ�ǧ��������������
          �项ֻ�������Ը���ȴ��֮�á�
����������
LONG
   );

}
void ask_vampire(object asker)
{
write(@LONG
����˵�����ȳ�����һ�߽��������������Ҫ��ʰ������ô����Ҷ�ʦ��
         ����ħ����(ghost_spell) �Ƚ���ʤ�㡣���ǣ��Դ��Ҷ�ʦ��
         ��۳ͷ�֮�ᣬ���䲻�����Ҿ���Ҳû���������ˡ�

LONG
   );
   asker->set_temp("wizelder",1);
}
int accept_item(object player, object item)
{
    object mark;
    if ( !item->query("basket_used")  ) {
       write("����Ц����лл���Ҳ���Ҫ����������\n");
       item->move(environment());
       return 1;
    }
    write(@LONG
����ӹ�����������ӣ�˵����
��������лл�㣬�����һ���ֻ�׹�����Ҳûʲ�ᶫ���ø���ģ�
������������˵�㵽�����������ʹ����������и����ƣ������
�������������Ͳ������������ˡ�
����������������������������
LONG
    );
    item->remove();
    mark=new(SWITEM"mark1");
    mark->move(environment());
    return 1;
}

void ask_building(object asker)
{
  write(@LONG
����˵�����춼��ûȥ���㣬����ȥ�ʱ��˰ɡ�  
LONG
  );  
}
void ask_older(object asker)
{
   write(@LONG
����˵������ʯ���ˣ�ร����Ǹ�Ƣ������Źֵ��ˣ��һ��������������棬
LONG
   );   
}
void ask_help(object asker)
{
  write(@LONG
����˵����ȥ�꣬������һֻ���׵Ĺ����м���(lucky)������С��Ů���棬
����      ǰ����ȴʧ���ˣ��������費˼�����룬�ҿ�Ҳ�ѹ������ܰ���
�����������һ�����        ������
LONG
   );
}
void ask_entrance(object asker)
{
   write("����˵���������ȥ�ʹ������������һ����(help)���Ҿ������跨��\n");
}
void ask_things(object asker)
{
   tell_room(environment(),@LONG
����˵�����ر�Ķ�����Ŷ�������ϵ�ħ��Ҳ���ر𰡣�

����˵�����������ħ��������ҫһ����^_^��
LONG
    );
}
void haha()
{
   delete_temp("block_command");
}
void cast_run(string type,string msg,string mob_name,int damage)
{
   object env,*all;
   int i,max;
   env=environment(this_object());
   all=all_inventory(env);
   tell_room(env,sprintf(msg,mob_name));
   max=sizeof(all);
   for (i=0;i<max;i++)
     if ( all[i]!=this_object() )
        all[i]->receive_special_damage(type,damage);
   k--;
   if ( !k ) call_out("haha",2);
}
void chn_attack()
{
  object victim,env;
  string mob_name,msg1,msg2,type;
  int damage,i;
  env=environment(this_object());
  mob_name=query("c_name");
  for ( i=1;i<3;i++) {
    k++;
    switch( random(3) ) {
    case 0:
       msg1=set_color(cast_msg1[0],"HIW");
       tell_room(env,sprintf(msg1,mob_name));
       msg2=set_color(cast_msg2[0],"HIW");
       type="cold";
       damage=50+random(10);
       call_out("cast_run",3,type,msg2,mob_name,damage);
       break;
    case 1:
       msg1=set_color(cast_msg1[1],"HIR");
       tell_room(env,sprintf(msg1,mob_name));
       msg2=set_color(cast_msg2[1],"HIR");
       type="fire";
       damage=45+random(15);
       call_out("cast_run",3,type,msg2,mob_name,damage);
       break;
    default:
       msg1=set_color(cast_msg1[2],"CYN");
       tell_room(env,sprintf(msg1,mob_name));
       msg2=set_color(cast_msg2[2],"CYN");
       type="devil";
       damage=55+random(5);
       call_out("cast_run",3,type,msg2,mob_name,damage);
       break;
    }
  }  
  set_temp("block_command",1);
}
int my_tactic()
{
    int i,max;
    object victim,env,*atk;
    string power,name;
    set("force_points",350);
    if ( !victim=query_attacker() ) return 0;
    env=environment(this_object());
    if ( time ) {
       if ( time>1 ) 
         tell_room( env,set_color("����������������һ�ž޴�Ľ���...\n","HIY"));     
       else {
         tell_room( env,set_color(sprintf(
            "������ǰһָ�����������Ľ���������һ������ʱը������Ѫ���ɣ�\n\n"),"HIY"));         
         if ( atk=all_inventory(env) ) {
            max=sizeof(atk);
            for(i=0;i<sizeof(atk);i++)
               if ( atk[i]!=this_object() ) 
                  atk[i]->receive_special_damage("electric",90+random(10));
         } 
       }
       time--;
       return 1;
    }
    switch( random(15) ) {
    case 0..2:
        if ( query_temp("block_command") ) break;
        chn_attack();
        break;
    case 3:
        time=3+random(1);
        break;    
    default :
        break;
    }
    return 0;
}
