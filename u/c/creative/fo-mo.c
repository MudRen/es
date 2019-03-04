//  �˺����� = 10 + ���(level) + ������/20  = (10~34)
//  skill=weapon_type_skill+piety*3+str*3+con+kar+(int)gonfu_level/5-victim(dex*2+piety*2+kar)
//  �� skill= (1~195) - victim( dex*2 + int*2 +kar)
//  ������=random(skill) > query_hit_chance(20 ~70) 
//  ��������= 3 ��

#include </u/w/wind/wind.h>
inherit DAEMON;


int query_fp_cost()     { return 20; }
int query_delay_time()  { return 18; }
int query_step()        { return 6; }
string query_name()     { return "fon-mo"; }
int gonfu_level = (int)this_player()->query("gonfus/"+query_name()) ;

int query_hit_chance()  {
  int i;  
  i=random(40); 
  return i;
}

int query_damage(){
  int i,level;
  
  level=this_player()->query_level();
  
  i=10 +random(level)+gonfu_level/20;
  return i;
}


int eungon(int gonfu_level,string victim_name)
{
    int chinese_mode,j,skill;
    object targ,ob1,*stats,weapon;
    mapping extra_stats;
    string type,weapon_name;

    ob1=this_player();
    chinese_mode = can_read_chinese();
    weapon=ob1->query("weapon1");
    if( weapon ) switch( weapon->query("type") ) {
                case "longblade" :      skill = 0;          break;
                case "shortblade" :     skill = 0;         break;
                case "dagger" :         skill = 0;          break;
                case "blunt" :          skill = 10;          break;
                case "axe" :            skill = 0;          break;
                case "thrusting" :      skill = 0;          break;
                case "polearm" :        skill = 5;          break;
                case "chain" :          skill = 0;          break;
                case "whip" :           skill = 0;          break;
                default:                skill = 0;
        } else skill = 0;

        if (skill<1){
           write( chinese_mode?
                "��û��װ�����õ�����������ʹ����ħ���� .... ��\n":
                "This weapon is not suit to use fon-mo skill, maybe a blunt is better... \n");
           return 1;
        }

        weapon_name=(string)weapon->query("c_cap_name"); 
        write( chinese_mode?
                "���ս����е�" + weapon_name + "��ʦ������ķ�ħ����һһ�������и��� .... ��\n ":
                "You begin to wave the polearm  ....\n"
        );
        tell_room(
          environment(ob1), ({ sprintf(""),
          sprintf(C_NAME + "�����е�" + weapon_name + "ƽ�٣�һ�����ƴ���չ¶..\n" )
          }),
          ob1
        );
      
       if ( !(victim_name=="NONE") ) { 
       targ=present( victim_name,environment(this_player()) );
       if(! targ ) {
          write(chinese_mode? "���Ŀ�겻������!!! \n":" it is not here!\n" );
          return 0;
                   } 
       if (!living(targ) ) {
          write(chinese_mode? "Ŀ�����������!\n":"It is not a living creature!\n");           
           return 0;       }
       if (targ->query("no_attack") ) {
           write(chinese_mode? "�����Դ�����!!! \n":"U cannot attack it! \n");
           return 0;                  }
       if (targ==this_player() ) {
           write(chinese_mode? "��ɱ��? ��Ҫ��.... :) \n":"Hmm.. u dont really want to do it? \n");
          return 0 ;                  }
                                      
               ob1->kill_ob(targ); 
               targ->kill_ob(ob1); 
                                      }


        ob1->set_temp("gonfu_busy",1); 
        ob1->set_temp("gonfu_now",query_name());  

        call_out( "gonfu_effect", query_step(), ob1, query_name(),skill );
        return 1;
}

void gonfu_effect( object player, string gonfu, int skill )
{
    int delay_time,j,damage1,db;
    string *stats,player_name;
    mapping extra_stats;
    object victim;

    
    if( gonfu != (string)player->query_temp("gonfu_now") ||
        !(delay_time = (int)player->query_temp("gonfu_delay_time")) ) { 
          player->set_temp("gonfu_now","");     
          player->set_temp("gonfu_busy",0);           

          write( can_read_chinese()?
   "\n��˫�ֺ�ʮ���չ�����...��\n":
                "You end the po-shan polearm skill....\n"
        );
        say(C_NAME+"�����й�������˫�ֺ�ʮ������˵��  �׳���...��\n");
    } else {
      delay_time -= query_step();
      victim=player->query_attacker();

///////////////////////////û�е���///////////////////////////////////
      if (!victim){
          write( can_read_chinese()?
                "�㽫����������һ�ң��ţ�..׼ȷ��������һֻ���ϡ�\n":
                " ....\n"
          );
          say(C_NAME+"������������һ�ң��ţ�..׼ȷ��������һֻ����... ������������..��\n");
       }
  else {     
          skill+=(int)player->query_stat("piety") *3 +(int)player->query_stat("str")*3+(int)player->query_stat("con")+(int)player->query_stat("dex")+gonfu_level/5;
          skill-=(int)victim->query_stat("dex")* 2+(int)victim->query_stat("piety")*2+(int)victim->query_stat("kar");     
          if (random(skill) >query_hit_chance()){
          damage1=query_damage();
          player_name=victim->query("c_cap_name");

//  �������������� һ���˺� �������������������
          if (damage1<15){
                write( can_read_chinese()?
                  "\n��ʹ����ħ�����е�һ�С��컨��������ֱ��"+player_name+"��\n\n":
                        " ....\n"
                );
         tell_room( environment(this_player()), ({ 
                 sprintf(""),
       sprintf("\n%s���еĹ���ʹ�����컨������%s��ȥ��\n\n",this_player()->query("c_cap_name"),player_name) }),
                 player
         );
        }
// ��������������� �����˺� ����������������
        else if (damage1<22){
           write( can_read_chinese()?
                  "\n��ʹ����ħ�����еĵڶ��С���ˮ�´̡����������ٵ�����"+player_name+"��ȥ��\n\n":
                        " ....\n"
           );
         tell_room( environment(this_player()), ({ 
                 sprintf(""),
                 sprintf("\n%s�������еĹ�����һ�С���ˮ�´̡�����%s���¡�\n\n",this_player()->query("c_cap_name"),player_name) }),
                 player
         );
        }
// �������������� �����˺� �������������������
        else if (damage1<30){
           write( can_read_chinese()?
                  "\n��ʹ����ħ�����ĵ����С�����ж�ס������治��Ľ����˴���"+player_name+"��Ҫ����\n\n":
                        " ....\n"
                );
         tell_room( environment(this_player()), ({ 
                 sprintf(""),
     sprintf("\n%s���һ����ֻ�������еĹ���һ�С�����ж�ס�ͻȻ����%s��\n\n",this_player()->query("c_cap_name"),player_name) }),
                 player
                );
        }       

// �������������� �ļ��˺� �������������������
        else if (damage1>=30){
           write( can_read_chinese()?
                  "\n��ʹ���˷�ħ����������һ�С�ѩ����\��������Ӱ�緭�ɴ�ѩ��Χ��"+player_name+"��\n\n":
                        " ....\n"
                );
         tell_room( environment(this_player()), ({ 
                 sprintf(""),
                 sprintf("\n%s����һ�����������趯��������ѩ���Ƕ������ع�Ӱ��Χ��%s��\n\n",this_player()->query("c_cap_name"),player_name) }),
                 player
                );              
        }
        player->gain_experience(damage1);  
//      victim->receive_special_damage("none",query_damage(),0);     
//       	db=(int)victim->query("defense_bonus");
//       	db=db*2/3;
//       	damage1=damage1-random(db);
    	victim->receive_damage(damage1,1);	
        victim->set("last_attacker",player);
    	"/d/gonfu/monk/message_tell"->report(player,victim);


    }
  }
      if( delay_time < 0 ) delay_time = 0;
      player->set_temp("gonfu_delay_time", delay_time );
      call_out("gonfu_effect", query_step(), player, gonfu,skill );
   }
        if(random(8)>=7 && gonfu_level<100 )
       { gonfu_level +=1;
         write (can_read_chinese()?
         "��ķ�ħ����\������������!!!\n":"your po-shan gonfu raised!!! \n");
         player->add("gonfus/"+query_name(),1);
      } 
}
