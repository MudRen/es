//#pragma save_binary
// acupunct.c
// 
// This is acupunct founction for chinese healers
// monsters can't use this command
// and players can only use this command on other players
// players can only be acupuncted when 
//     he placed himself in relax situation 
// create by Indra@Eastern_Story on 11.28.93
//

#include <mudlib.h>
#include "/d/healer/healer.h"
#define CHECK_USE "/d/healer/acupuncture/use_points"
#define CHECK_ALL "/d/healer/acupuncture/points"
#define part ({"������λ","ͷ��","����","��ǰ","����","����","����","����","�Ȳ�"})

inherit DAEMON ;

int help() ;

//  this func is to check if the point have been acupuncture
//
int check_repeat(string tar_pt,string *acup_pts)
{
     int i,j ;
     string temp ;
   
     j = sizeof(acup_pts);
    
     if(j==0) return 1 ;
     for(i=0;i<j;i++)
       { 
         temp = acup_pts[i] ;
         if(tar_pt == temp)
            return 0 ;
        }
     return 1 ;        
}
int remove_block(object obj)
{
    obj->delete_temp("block_command") ;
    return 1 ;
}
//
//  to do acupuncture
//
int do_acupuncture(string tar_point,object target)
{
       int dam,i,acu_sk,con_sk,my_dex,tar_con,tar_dex,living_flag,*result;
       string point,tar_name,part_name,*acuped,my_name;
       mapping learned_merid ;
       object me ;
       
       me = this_player() ;
       my_name = me->query("c_cap_name") ;
 
       acu_sk = me->query_skill("acupuncture") ;
       con_sk = me->query_skill("concentrate") ;
       tar_name = target->query("c_cap_name") ;  
       tar_con = target->query_perm_stat("con") ;
       tar_dex = target->query_perm_stat("dex") ;
       my_dex  = me->query_perm_stat("dex") ;
       if(acu_sk>100) acu_sk = 100 ;
       if(con_sk>100) con_sk = 100 ;

       living_flag = living(target) ;
       learned_merid = me->query("prac_meridians") ;
       if(!learned_merid) learned_merid = ([ ]) ; 

       result = CHECK_USE->do_check(tar_point,learned_merid) ;
       
       if( result[1] == -1 )
          {
           write("��û��ϰ����������,û���϶���ȷ��λ��,�������롣\n") ; 
           return 1 ;
           }  
       if( (result[0]==1) && (living_flag) )
         {
           if(target == me)
             {
                write("����ɱ��SUICIDE�͹���,��Ҫ̫Ű���Լ���\n") ;
                return 1 ;
             } 
           me->set_temp("block_command",2) ; 
           target->kill_ob(me) ;
           part_name = part[result[1]] ;         

          if(random(my_dex+acu_sk/2+con_sk/2) > tar_dex*2 ) 
            {
              dam = ((acu_sk+con_sk)*10)/(tar_con+tar_dex) ;
              target->receive_damage(dam) ;
        
              write(sprintf("����������%s%s��%sѨ������ȥ��\n"
                            "��һ����ҵİ�����,����ʼ�����㡣\n"
                            ,tar_name,part_name,tar_point) );
              
              me->block_attack(2) ;
              me->set_temp("msg_stop_attack",
                      "( һ��Υ����ͳ���¼�ֵ�ı�̬���������������ս���С� ) \n" ) ;
                         
              tell_object(target,sprintf(
                        "%s����%s��%sѨ������ȥ��\n"
                        "��һ���ʹ��,�㿪ʼ����%s��\n"
                        ,my_name,part_name,tar_point,my_name) ) ;
                                 
              tell_room(environment(me),sprintf(
                        "%s�ó�������%s%s������ȥ,����һ���ҽ�,\n"
                        "%s��ʼ����%s��\n"
                        ,my_name,tar_name,part_name,tar_name,my_name)
                        ,({me,target}) ) ;
              call_out("remove_block",3,me) ;
             }
           else
             {
              write(sprintf("������������%s%s��%sѨ����ȥʱ��\n"
                            "���ƺ������������ͼ����ʼ�����㡣\n"
                            ,tar_name,part_name,tar_point) );
              
              tell_object(target,sprintf(
                        "%s����%s��%sѨ�����������㷢�����������⡣\n"
                        "������ȷ����˿�ʼ����%s��\n"
                        ,my_name,part_name,tar_point,my_name) ) ;
                                 
              tell_room(environment(me),sprintf(
                        "%s�ó�������%s%s������ȥ,����%s���һ��: "
                        "�� ������ʲ��? ��\n"
                        "%s��%s��֪����ľʹ���������\n"
                        ,my_name,tar_name,part_name,tar_name,tar_name,my_name)
                        ,({me,target}) ) ;
              call_out("remove_block",3,me) ;
             }

           return 1 ;
        }

// ������ѨҲ������ЧѨ, ��ȫ����

        if( result[0] == 0 )
            result = CHECK_ALL->do_check(tar_point) ;

       if( result[1] == -1 )
           return notify_fail("��û��ϰ����������,û���϶���ȷ��λ��,�������롣\n") ; 

// Ok , had checked point, now do effective acupuncture

        if(result[0]!=1&&result[0]!=2&&result[0]!=3)
           { 
            write("û�����Ѩ����\n") ;
            return 1 ;
           } 
           
        if(living_flag)
          acuped = target->query_temp("acupuncted_pts") ;
        else
          acuped = me->query_temp("practice_pts") ;
 
        if(!acuped) acuped = ({ }) ;

// check if the point once been acupuncture....
        
        if(check_repeat(tar_point,acuped)==0)
          {
             write("�Ǹ�Ѩ���Ѿ������������ˡ�\n");
             return 1 ;
          }
        acuped = acuped + ({ tar_point }) ;

        part_name = part[result[1]] ;
        if((((string)target->query("race"))=="hawkman")&&(result[1]==7))
               part_name = "�����" ;
        
        if(target==me)
            {
             tar_name = "�Լ�" ;
             if(result[1]==6)
                { 
                tell_object(me,"���벻���Լ��ı���\n") ;
                return 1 ;
                }
             }   
        else{ 
             tell_object(target,sprintf("%s����������%s��%sѨ������ȥ��\n"
                         ,my_name,part_name,tar_point)) ;          
             }
             
        write(sprintf("����������%s%s��%sѨ������ȥ��\n"
                        ,tar_name,part_name,tar_point));

        tell_room(environment(me),sprintf("%sȡ��������%s%s������ȥ��\n"
                                 ,my_name,tar_name,part_name),({me,target}) ) ;

        if(living_flag)
          {
//            target->set("acupuncted_pts",acuped) ;
            target->set_temp("acupuncted_pts",acuped) ;       
           }
        else
          {
            me->set_temp("practice_pts",acuped) ;
//            me->set("practice_pts",acuped) ;
           }
       return 1 ;
}

// this is main part of acupuncture command,
// major for check all situations when u wanna do acupuncture

int cmd_acupunct (string str)
{
	string targetname, point, code, donator,my_name;
	object target,me ;
  
        me = this_player() ;
        my_name = me->query("c_cap_name") ;

	if( !str ) return help();

//        if(!wizardp(me))
//                return notify_fail("���������ʱֻ���Ÿ���ʦ�����á�\n") ;
                
        if(!( !(me->query_current_attacker()) ))
                return notify_fail("�㻹��ս����,ûʱ��ͣ�������롣\n");
         
	if( !me->query("vision") )
      		return notify_fail("�㿴����Ŀ�꣬û�취���� !!\n"); 
	
	if( me->query("weapon1") && ( me->query("weapon2") ||
	     me->query("armor/shield") ) )
	    return notify_fail( "��û�ж��ŵ�����ȡ�� !!\n" );

        if( me->query_temp("no_concentrate"))
            return notify_fail("���ע���������ܼ���,�޷�ר�����롣\n") ;
             
	if( (int)me->query("stop_attack")>0 )
	    return notify_fail ("����һ��������û����ɣ�����ר�����롣\n" );
            
        if ( sscanf( str,"remove from %s",targetname)==1 || 
             sscanf( str,"remove %s",targetname)==1 )
            {
              if(!(targetname)) target = me ;
              else 
               {
                if(!(target=present(targetname,environment(me))))
                     return notify_fail("�����˭���� ??\n") ;
               }  
              if(!target->query_temp("acupuncted_pts"))
                 return notify_fail("������ë��û����, Ҫ��ʲ���� ? \n") ;
                 
              target->delete_temp("acupuncted_pts");   
              target->delete("acupuncted_pts");                 
              target->delete_temp("acupunct_healer") ;
//for debug write(me->query("c_cap_name")+" "+target->query("c_cap_name")+"\n") ;
              if(target==me)
                {
                  write("�㽫�Լ�����������һ�����İγ�����\n") ;
                  targetname == "�Լ�" ;
                }
              else 
                {
                  targetname = target->query("c_cap_name") ;
                  write(sprintf("�㽫%s����������һ�����İγ�����\n"
                                 ,targetname)) ;
                  
                  tell_object(target,sprintf("%s��������������һ�����İγ�����\n"
                         ,me->query("c_cap_name"))) ;
                }
              tell_room(environment(me),sprintf("%s��%s����������һ�����İγ�����\n"
                          ,me->query("c_cap_name"),targetname)
                          ,({me,target}) ) ;
                            
              return 1 ;
            }
            
	if ( sscanf( str,"%s at %s", targetname,point)==2|| 
             sscanf( str,"%s on %s", targetname,point)==2 )
	     {
	      if((targetname=="model")||(targetname=="brozen model"))
	        {
	          if(!(target=present(targetname,environment(me)))
	             &&(!(target=find_player(targetname))))
	               return notify_fail("����û�����������\n") ;
	         }
	      else if(!(target=find_player(targetname)))
	              return notify_fail("�������û��������\n") ;
              
              if(!present( target,environment(me) ))
                 {
                   tell_room(environment(me),me->query("c_cap_name")+
                       "��������Կ��пյ�������,Ȼ�ῴ�˿����ܴ�����Ц�����·��\n"+
                       "���������������롣\n",me) ;                              
                   return notify_fail
                         ("����Ϊ��������֮���� ? ���������ġ�\n");
                   }
	      } 
	else {
	       if(sscanf( str,"%s",point)==1)
            	      target = me ;
               else
                  return help() ;
	      }

	if((target->query("npc"))&&(!(target->query("acupunctable"))) )
	       return notify_fail("���޷��Է���ҽ�ɫʩ����ġ�\n ") ;    

        if(!( !(target->query_current_attacker()) ))
                return notify_fail("���Ŀ�껹��ս����,ûʱ��ͣ�����������롣\n");

        donator = target->query_temp("acupunct_healer") ;

        if((!(!donator))&&donator!=my_name )
                return notify_fail("��Ķ������ڽ��������,�㲻����;���롣\n");
                
        if((string)target->query("race")=="beholder") 
           return notify_fail("�Է�����̫�����,�㲻֪�Ӻ����롣\n") ;
           
        do_acupuncture(point,target) ;
        
	return 1;
}
 
int help()
{
	write( @C_HELP
ָ���ʽ: acupunct <Ŀ��> [on|at] <Ѩ������>
          acupunct remove from <Ŀ��>

���ָ����������ʩչ�������񼼣���ָ��Ŀ�������Լ����룬����ЩѨ��
���Լ��벻����������� meridian ָ���Ŀǰ�Ѿ�ѧ���ľ����б�Ϊ���˶�
���ӣ�һ�����߱����������ᣬ��������һλҽ���롣 ���������Ի���ʩ��
������<������>�Լӿ���Ч��(������� help douin)

�˹�������Ϊ max, regular, normal, minor, mini ��
���Ⱥúÿ�����������룬��Ѫ�����д�������ʱ�����ܻ����������˹��ߡ�
�������ˣ����߲з�̱������֮��֮...

Ϊ��ȡѨ��ȷ������ʩ������ǰ����Ҫ��ͭ���Ͻ���Ѩ�������ľ������졣
C_HELP
		);
    return 1;
}
