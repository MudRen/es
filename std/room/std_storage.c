// This is a room for storage eqs , and can filter some "garbage"
//       by Indra@EasternStories
//
// This one is Ver1.1 use call_other , and old ver(ver1.0) use call_out
//

#include <mudlib.h>
#define DROP "/cmds/std/_drop.c"
#define GET "/cmds/std/_get.c"

inherit ROOM;

int AMOUNT = 0 ;
int COUNT = 0 ;
nomask int my_clean_func() ;
string cleaning_msg() ;

void create()
{
	::create();
        set_short("标准储藏室");
	set_long(
@C_LONG_DESCRIPTION
用来作范例的标准公会储藏室。墙上有张告示(note)。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
        set( "item_desc", ([
 		"note": "储藏室是用来放武器防具容器等重要物资的,空间有限\n"
 		        "请不要当垃圾堆般的堆放无用途的东西。\n" 
 		           ]) );
	set( "exits", ([ 
		"out" : "/d/healer/building/healer_guild"
		       ]) ) ;

	//	     
	//以下各设定请各 arch 视自己需要及公会状况做修改...
        //
		     
        set("max_amount",50) ;	             //这个房间清过後物件储存的最大值 
	set("class_name","NONE") ;           //这个房间所在公会名称, 用以清除
	                                     //该公会成员不能用的装备.
        
        //两数分别代表最低容许之WC,dam平均值
        
	set("weapon_res",({23,17}) ) ; 

	//每种型别防具之ac,db最低容许值,限制为 ac+db 之合 
        //如果能改变AC DB的,请在防具 set("no_clean",1)
        
        set("armor_res",([                          
                         "body" : 20   , "legs"   : 9 ,
 	                 "feet" : 7    , "cloak"  : 8 , 
 	                 "head" : 7    , "arms"   : 6 , 
 	                 "misc" : 5    , "finger" : 5 , 
 	                 "hands" : 6   , "globe"  : 25 , 
 	                 "shield" : 7  , "saddle" : 11 , 
 	                 "kernal" : 6  , "tail"   : 8 ,
 	                 "others" : 8,
 	                 ]) ) ;
	
	//容器的限制
	set("container_res",200) ;
	
        // 以下是清除的讯息, 有必要的话请重写 string cleaning_msg()
	set("clean_msg",
	    "%s走进这个房间一看,摇了摇头,招来一阵闪电,把没用的东东烧成灰。\n") ;
	set("msg_arg","雷神之子") ;
	
	reset();
}

void init()
{
     add_action("do_drop","drop") ;
     add_action("do_get","get") ;
}

int do_get(string arg)
{
    if(GET->cmd_get(arg)==0)              // 直接使用正常的get 命令(房间呼叫)
         return 0 ;                       // 如果失败(0), 则传回0.
                                          // 再跑一次get 的动作(玩家呼叫)
    if(arg=="all")                        // 一次get all 视为五次get的效果
       AMOUNT -= 5 ;
    else 
       AMOUNT -- ;
       
    ( AMOUNT < 0 )? 0 : AMOUNT ;          // 数目小於0 时设回 0
    
    return 1 ;
}

int do_drop(string arg)
{
    if(DROP->cmd_drop(arg)==0)            // 同get
         return 0 ;
 
    if(arg=="all")                        // 一次drop all 视为五次drop 的效果
       {                                  // 但另增一个变数 COUNT
          AMOUNT += 5 ;                   // 以防止重覆get all,drop all的情形
          COUNT++ ;
        }
    else
       AMOUNT++ ;
    
    if( AMOUNT > 25 || COUNT > 8 )
      { 
         this_object()->my_clean_func() ;
         AMOUNT = 0 ;
       }
    return 1 ;
}

nomask int my_clean_func()
{
     object *inv,temp,it ;              // 一堆变数..
     int i,number,res1,res2,temp1,temp2,temp3,check_flag ;
     string type,inherit_from,ob_sort ;

     inv = all_inventory(this_object()) ;          // 首先check房间中的东东
     number = sizeof(inv) ;
     
     for(i=0;i<number;i++)
        {
           it = inv[i] ;
           check_flag = 0 ;                       // 物品限制初始化
           res1=res2=temp1=temp2=temp3=0 ;        // 再check 物品的种类.
                                                  // 用inherit list 是怕
           inherit_from = inherit_list(it)[0] ;   // 用物品的特徵设定可能误判
           ob_sort = "/"+explode(inherit_from,".")[0] ;      

           // if that item have no_clean flag , then skip 
           // 玩家和有 no_clean 设定的就直接跳过..

           if(it->query("no_clean")|| ob_sort==USER ) continue ;
           
           switch(ob_sort)
             {
                case LIVING :
                              check_flag = 1 ; 
                              break ;
                case WEAPON :
                              temp1 = it->query("weapon_class") ;
                              temp2 = it->query("max_damage") ;
                              temp3 = it->query("min_damage") ;
                              res1 = query("weapon_res")[0] ;
                              res2 = query("weapon_res")[1] ;
                              
                              if(((temp1<res1)||((temp2+temp3)<res2*2)) )
                                 check_flag = 1 ;                                 
                              break ;
                case ARMOR  :                
                              temp1 = it->query("armor_class") ;
                              temp2 = it->query("defense_bonus") ;
                              type = it->query("type") ;
                              res1 = query("armor_res/"+type) ;
                              if(!(res1)) res1 = query("armor_res/others");
                         
                              if((temp1+temp2)<res1)
                                  check_flag = 1 ;
                              break; 
                case CONTAINER :                
                              temp1 = it->query("max_load") ; 
                              res1 = query("container_res") ;
                              
                              if(temp1<res1 )
                                  check_flag = 1 ;
                              break; 
                default : check_flag = 1 ;
                          break ;  
              }                          
         
           if(check_flag)
             {
//               tell_room(this_object(),
//                           it->query("c_name")+"该被除去。\n",) ;
               it->remove() ;
               }
        }

     inv = all_inventory(this_object()) ;
     number = sizeof(inv) ;
     res1=res2=temp1=temp2=temp3=0 ;     
     res1 = query("max_amount") ;
  
 // 东东真的太多了, 不得不清 .. 连有no_clean flag 的也会清掉
 // 如果限制为50,则当超过 75 件时, 清掉 75-50 = 25 件.剩50样
 
     if( number>(res1*3/2) )
        {  
           temp2 = number - res1 ; 
           for( i=number;;--i )
              {
                 if(temp1==temp2) break ;
                 if(living(inv[i])&&!(inv[i]->querry("npc")) )                 
                    continue ;
                    
                 inv[i]->remove() ;
                 temp1++ ;
              } 
         }
//  告诉玩家垃圾车刚刚开走..
                     
     tell_room(this_object(),cleaning_msg(),) ; 
     return 1 ;     
}

string cleaning_msg()
{
   return sprintf(query("clean_msg"),query("msg_arg")) ;
}

int clean_up() 
{
     return 0;
}

