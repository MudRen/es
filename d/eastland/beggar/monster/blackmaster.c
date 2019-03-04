#include "/d/eastland/beggar/dony.h"
inherit MONSTER;

object ob1;

void create()
{
        ::create();
        set_level(17);
        set_name( "blackmaster Lu", "½����" );
        add("id",({"blackmaster","lu"}));
        set_short( "�ɽ� ½����");
        set("unit","λ");
        set_long( @LONG
½����ԭ���ǡ������š������˲��Ҵ�ʦ�Ŵ�ѧ��һ������ա� �������߽�����
��Ϊ������,���еı���ֻҪ������������������ľҲ�ܶϽ𡣽��������ܵ�ʦ��
��ͽ���Ⱥ����Ⱦӵ���н���塻��,������ϣ��������һ���ܹ��������е�ʦ��
���ࡣ
LONG
        );
        set("weight",750);
        set_perm_stat("str",30 );
        set_perm_stat("dex",24 );
        set_natural_weapon(50, 18, 38);
        set_natural_armor( 83, 29 );
        set_skill("parry",80);
        set_skill("block",80);
        set("max_hp",620);
        set("hit_points",620);
        set("gender", "male");
        set("race", "human");
        set("war_score",50000);
        set("alignment",1500);
        set("special_defense", ([ "all": 40,"none":30]) );
        set("aim_difficulty",
          ([ "critical":65, "vascular":60, "ganglion":80, "weakest":65 ]) );
        set( "inquiry", ([
               "master":"@@ask_master",
            ]) );
        wield_weapon(DWEAPON"sky_sword.c");
        equip_armor(DARMOR"orb_shield.c");
        equip_armor(DARMOR"fire_armband.c");
}
void ask_master(object asker)
{
     
//     if( (int)asker->query_quest_level("dony1") ) 
     if ( !asker->query("finish_dony") )
        tell_object( asker , "½����˵��:�����ҵ�������˷���,���ƺ������鷳�ˡ�\n");  
     else {
        if ( ( asker->query("class") ) == "scholar" ){
           if ( present("spell",asker) ) 
              tell_object( asker , "½����˵��:��,�㲻���Ѿ����˾۽�����?\n");
           else {
              tell_object( asker, 
                "½����˵��:����˷����������й�춾۽���?\n"
                "½����˵��:�ð�,�����۽����ǲ���㴫�ڸ��˵�,��Ȼ�����ҵ�����,���Ҿͽ����!\n"
                "��Ȼ½����������\n");
              call_out("recover1",2,asker);                     
           }     
        } else tell_object( asker , "½����˵��:лл��İ����ҵ�����\n");
     }   
}

void recover1(object asker)
{
     tell_object( asker,
         "\n\n����½���ɵ��۾�����һ�����Χ������,�㿴�������еĶ���!!\n\n\n");
     asker->set_temp("block_command",1);
     call_out("recover2",10,asker);
}
void recover2(object asker)
{
   asker->set_temp("block_command",0);
   tell_object(asker,
       "�ǵ�Χ���������ԵĽ��þò�ɢȥ,�����������������һ��������\n"
       "½���ɽ�����˵��:���Ӳ�Ҫ˯��,��������,���Ѿ����ڸ���۽����ˡ�\n"
       "�㿴���Լ�,��!�۽���!!����˵���½����˵лл��\n"
       "½��������΢Ц��^_^\n");
   ob1 = new( DITEM"spell" );
   ob1->move(asker);
}
void die()
{
   object killer;
   string str,name;
   if ( killer=query("last_attacker") ) {
     if ( killer->query("org_name") ) name=killer->query("org_name");
     else name=killer->query("name");
   }
   str="\n  "+ctime(time())+" ½���� killed at "+
    file_name(environment(this_player()))+" by "+name+"\n";
   write_file("/open/dony/deathlist",str);
   ::die();
 }