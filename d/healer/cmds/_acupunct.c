////#pragma save_binary
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
#define part ({"不明部位","头部","颈部","胸前","腹部","腰部","背部","手上","腿部"})

inherit DAEMON ;

int help() ;

//  this func is to check if the point have been acupuncture
//
int check_repeat(string tar_pt,string *acup_pts)
{
     if( member_array(tar_pt,acup_pts) != -1 ) return 0 ;     
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
       my_name = me->query("c_name") ;
 
       acu_sk = me->query_skill("acupuncture") ;
       con_sk = me->query_skill("concentrate") ;
       tar_name = target->query("c_name") ;  
       tar_con = target->query_perm_stat("con") ;
       tar_dex = target->query_perm_stat("dex") ;
       my_dex  = me->query_perm_stat("dex") ;
       if(acu_sk>100) acu_sk = 100 ;
       if(con_sk>100) con_sk = 100 ;

       living_flag = living(target) ;

       learned_merid = me->query("prac_meridians") ;
       if(!learned_merid) learned_merid = ([ ]) ; 

       result = CHECK_USE->do_check(tar_point,keys(learned_merid)) ;
       
       if( result[1] == -1 )
          {
           write("你没练习过这条经络,没法肯定正确的位置,不敢下针。\n") ; 
           return 1 ;
           }  
       if( (result[0]==1) && (living_flag) )
         {
           part_name = part[result[1]] ;                  
//         "/d/healer/acupuncture/fatal.c"->damage(me,target,tar_point,part_name) ;
           if(target == me)
             {
                write("想自杀打SUICIDE就够了,不要太虐待自己。\n") ;
                return 1 ;
             } 
           if(target->query_level()<5)
             {
                write("大神往你脑袋敲了下去说道: 不要欺负小朋友。\n") ;
                tell_room(environment(me),me->query("c_name")+"的手突然伸到"+
                      target->query("c_name")+"面前,正当千钧一发之际,\n他的手莫名其妙的僵住, 头上同时多了好几个包。\n",me);
                return 1;
             }  
           me->set_temp("block_command",2) ; 
           target->kill_ob(me) ;


          if(random(my_dex+acu_sk/2+con_sk/2) > tar_dex*2 ) 
            {
              dam = ((acu_sk+con_sk)*10)/(tar_con+tar_dex) ;
              target->receive_damage(dam) ;
        
              write(sprintf("你用银针往%s%s的%s穴扎了下去。\n"
                            "在一声凄惨的哀号後,他开始攻击你。\n"
                            ,tar_name,part_name,tar_point) );
              
              me->block_attack(2) ;
              me->set_temp("msg_stop_attack",
                      "( 一种违抗传统道德价值的变态快感让你忘了正在战斗中。 ) \n" ) ;
                         
              tell_object(target,sprintf(
                        "%s往你%s的%s穴扎了下去。\n"
                        "在一阵巨痛後,你开始攻击%s。\n"
                        ,my_name,part_name,tar_point,my_name) ) ;
                                 
              tell_room(environment(me),sprintf(
                        "%s拿出银针往%s%s扎了下去,随著一声惨叫,\n"
                        "%s开始攻击%s。\n"
                        ,my_name,tar_name,part_name,tar_name,my_name)
                        ,({me,target}) ) ;
              call_out("remove_block",3,me) ;
             }
           else
             {
              write(sprintf("当你用银针往%s%s的%s穴扎过去时。\n"
                            "他似乎发现了你的意图而开始攻击你。\n"
                            ,tar_name,part_name,tar_point) );
              
              tell_object(target,sprintf(
                        "%s往你%s的%s穴扎了下来。你发现他不怀好意。\n"
                        "於是你先发制人开始攻击%s。\n"
                        ,my_name,part_name,tar_point,my_name) ) ;
                                 
              tell_room(environment(me),sprintf(
                        "%s拿出银针往%s%s扎了下去,但是%s大喝一声: "
                        "『 你想做什麽? 』\n"
                        "%s和%s不知怎麽的就打了起来。\n"
                        ,my_name,tar_name,part_name,tar_name,tar_name,my_name)
                        ,({me,target}) ) ;
              call_out("remove_block",3,me) ;
             }

           return 1 ;
        }

// 不是死穴也不是有效穴, 到全表找

        if( result[0] == 0 )
            result = CHECK_ALL->do_check(tar_point) ;

       if( result[1] == -1 )
           return notify_fail("你没练习过这条经络,没法肯定正确的位置,不敢下针。\n") ; 

// Ok , had checked point, now do effective acupuncture

        if(result[0]!=1&&result[0]!=2&&result[0]!=3)
           { 
            write("没有这个穴道。\n") ;
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
             write("那个穴道已经有针在上面了。\n");
             return 1 ;
          }
        acuped = acuped + ({ tar_point }) ;

        part_name = part[result[1]] ;
        if((((string)target->query("race"))=="hawkman")&&(result[1]==7))
               part_name = "翅膀上" ;
        
        if(target==me)
            {
             tar_name = "自己" ;
             if(result[1]==6)
                { 
                  tell_object(me,"你针不到自己的背。\n") ;
                  return 1 ;
                }
             }   
        else{ 
             tell_object(target,sprintf("%s用银针往你%s的%s穴扎了下去。\n"
                         ,my_name,part_name,tar_point)) ;          
             }
             
        write(sprintf("你用银针往%s%s的%s穴扎了下去。\n"
                        ,tar_name,part_name,tar_point));

        tell_room(environment(me),sprintf("%s取出银针往%s%s扎了下去。\n"
                                 ,my_name,tar_name,part_name),({me,target}) ) ;

        if(living_flag) target->set_temp("acupuncted_pts",acuped) ;       
        else me->set_temp("practice_pts",acuped) ;
       return 1 ;
}

// this is main part of acupuncture command,
// major for check all situations when u wanna do acupuncture

int cmd_acupunct (string str)
{
	string targetname, point, code, donator,my_name;
	object target,me ;
  
        me = this_player() ;
        my_name = me->query("c_name") ;

	if( !str ) return help();

//        if(!wizardp(me))
//                return notify_fail("现在针灸暂时只开放给巫师测试用。\n") ;
                
        if(!( !(me->query_current_attacker()) ))
                return notify_fail("你还在战斗中,没时间停下来拿针。\n");
         
	if( !me->query("vision") )
      		return notify_fail("你看不见目标，没办法下针 !!\n"); 
	
	if( me->query("weapon1") && ( me->query("weapon2") ||
	     me->query("armor/shield") ) )
	    return notify_fail( "你没有多馀的手来取针 !!\n" );

        if( me->query_temp("no_concentrate"))
            return notify_fail("你的注意力还不能集中,无法专心下针。\n") ;
             
	if( (int)me->query("stop_attack")>0 )
	    return notify_fail ("你上一个动作还没有完成，不能专心下针。\n" );
            
        if ( sscanf( str,"remove from %s",targetname)==1 || 
             sscanf( str,"remove %s",targetname)==1 )
            {
              if(!(targetname)) target = me ;
              else 
               {
                if(!(target=present(targetname,environment(me))))
                     return notify_fail("你想拔谁的针 ??\n") ;
               }  
              if(!target->query_temp("acupuncted_pts"))
                 return notify_fail("你连根毛都没看到, 要拔什麽针 ? \n") ;
                 
              target->delete_temp("acupuncted_pts");   
              target->delete_temp("acupunct_healer") ;
              if(target==me)
                {
                  write("你将自己身上扎的针一根根的拔出来。\n") ;
                  targetname == "自己" ;
                }
              else 
                {
                  targetname = target->query("c_name") ;
                  write(sprintf("你将%s身上扎的针一根根的拔出来。\n"
                                 ,targetname)) ;
                  
                  tell_object(target,sprintf("%s将你身上扎的针一根根的拔出来。\n"
                         ,my_name)) ;
                }
              tell_room(environment(me),sprintf("%s将%s身上扎的针一根根的拔出来。\n"
                          ,my_name,targetname)
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
	               return notify_fail("这里没有这个东东。\n") ;
	         }
	      else if(!(target=find_player(targetname)))
	              return notify_fail("这个世界没有这号人物。\n") ;
              
              if(!present( target,environment(me) ))
                 {
                   tell_room(environment(me),me->query("c_name")+
                       "拿起银针对空中空点了两下,然後看了看四周带著耻笑神情的路人\n"+
                       "红著脸收起了银针。\n",me) ;                              
                   return notify_fail
                         ("你以为你是雷神之子吗 ? 竟想隔空针灸。\n");
                   }
	      } 
	else {
	       if(sscanf( str,"%s",point)==1)
            	      target = me ;
               else
                  return help() ;
	      }

	if((target->query("npc"))&&(!target->query("acupunctable")) )
	       return notify_fail("你无法对非玩家角色施以针灸。\n ") ;    

        if(!( !(target->query_current_attacker()) ))
                return notify_fail("你的目标还在战斗中,没时间停下来让你下针。\n");

        donator = target->query_temp("acupunct_healer") ;

        if( donator && donator!=my_name )
                return notify_fail("你的对象正在接受针灸中,你不能中途介入。\n");
                
        if((string)target->query("race")=="beholder") 
           return notify_fail("对方长的太奇怪了,你不知从何下针。\n") ;
           
        do_acupuncture(point,target) ;
        
	return 1;
}
 
int help()
{
	write( @C_HELP
指令格式: acupunct <目标> [on|at] <穴道名称>
          acupunct remove from <目标>

这个指令让你用来施展你的针灸神技，不指定目标则会对自己下针，但有些穴道
你自己针不到。你可以用 meridian 指令看你目前已经学过的经络列表。为免人多
手杂，一个患者必需完成针灸後，才能让另一位医生针。 针完後必须对患者施以
导引术<即气功>以加快疗效。(详情请见 help douin)

运功出力可为 max, regular, normal, minor, mini 。
请先好好考虑清楚再下针，当血气运行错误受阻时，可能会逆流冲向运功者。
轻者受伤，重者残废瘫痪，慎之慎之...

为求取穴正确，对人施针治疗前必须要在铜人上将该穴道所属的经络练熟。
C_HELP
		);
    return 1;
}
