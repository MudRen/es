#include <mudlib.h>
#include "/d/healer/healer.h"

#define DIV "...................."

inherit "/std/room/std_storage.c";

int view_note() ;
void create()
{
	::create();
        set_short("Healer's study room", "行医者书房");
	set_long(
@C_LONG_DESCRIPTION
这里是医生传承知识的地方。偌大的空旷房间, 在靠三边的墙边都有桌椅
供用功的行医者钞录笔记, 记录心得。而正面对你的那面墙, 则是放置全部的
医经的书柜(closet)。 你应该能从书柜中找到许多有用的书, 并从中得到许多
宝贵的知识。而中间一根柱子上刻著『惜福』两个大字。原来这里也是医生们
为照顾晚辈而专门设置的储藏室。再仔细一看.. 似乎旁边有一行字(note)。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
        set( "item_func", ([
 		"closet": "view_closet" 
 		           ]) );
	set( "exits", ([ 
		"north" : "/d/healer/building/healer_inner"
		       ]) );
	set( "max_amount",50) ;               //这个房间清过後物件储存的最大值
        set("weapon_res",({10,0}) );
    set("class_name","healer") ;           //这个房间所在公会名称, 用以清除
	                                      //该公会成员不能用的装备.
	set("msg_arg","彩虹仙子");                                                     
//     reset();              //咦..储藏室还加这行?....hch.
}

 int clean_up() {return 0; }

void init()
{
   ::init() ;
   add_action("do_read","read") ;
   add_action("view_closet","search") ;
}

string query_intro()
{
    string intro ;

    intro = "\t    针灸是由东方大陆发源的神秘医技。相传最早是由一位名为\n"
            "\t『如风』的医生开始使用针疗的方法来治病。然而最离奇的是\n"
            "\t张医生总是来无影去无踪,有怪病的地方就出现他的行迹,也顺便\n"
            "\t教导他人针灸的方法。当针灸普及全大陆後, 就再没人见过他的\n"
            "\t踪迹。於是, 就有张大夫是wing大神的说法开始流传。\n"
            "\t然而却没有人能证实这项说词。但是我个人认为, 这就像医界中\n"
            "\t传言我是那个专门到处吓人的色狼—雷神之子。一样无稽。\n"
            "\t                                湘东儒医  韩清逸\n"
            "\n\n\t下一页则是本书的索引(index)。\n"
            "\t内容则是在各页(page)中。\n" ;
 
    return intro ; 
}

string query_index()
{
    int i,size ;
    string msg, *merid, *eff ;
    
    merid = ALL_POINTS->query_meridians()  ;
    eff = USE_POINTS->now_working()   ; 
    
    msg = "\t索引:\n" ;    
    
    size = sizeof(merid) ;
    for(i=1;i<size;i++)        
       msg = msg + sprintf("%s%-20s%s%s%5d\n","\t\t",merid[i],DIV,"page",i) ;

    msg = msg + "\t以下是已知有作用的穴道群\n" ;
    size = sizeof(eff) ;
    for(i=0;i<size;i++)        
       msg = msg + sprintf("%s%-20s%s%s%5d\n","\t\t",eff[i],DIV,"page",i+100) ;
           
    return msg ;
                
}

string page_contain(int page)
{
    int i,size ;
    string msg,*merid_eff,describ ;
    
    i = page ; 
    if( page < 100 )
      {
        merid_eff = ALL_POINTS->query_meridians_by_no(page) ;
//        describ = ALL_POINTS->query_merid_describ(page) ;
       } 
    else
      {
        page =page - 100 ;
        merid_eff = USE_POINTS->query_eff_pts(page) ;
 //       describ = USE_POINTS->query_eff_describ(page) ;
       }     
    
    if(!merid_eff||(size=sizeof(merid_eff))==0)
       return "你把这本书上上下下左左右右前前後後全翻遍了,\n"
              "但就是找没有这麽一页。\n" ;

    msg = sprintf("\t第%d页......%10s的穴道群, 共%d穴\n",i,merid_eff[0],size-1) ; 
//    msg = msg + describ ;

    for( i=1 ; i<size ; i++ ) {
      if (stringp(merid_eff[i]))
      msg = msg + (string)sprintf("\t\t%s\n",merid_eff[i]) ;
    }       
    return msg ;
}

int do_read(string str)
{
    int page_no ;
    string arg ;
        
    if(!str)
      return notify_fail("你想读什麽 ??\n") ;

    if(str=="针灸治要"||str=="book"||str=="bible")
      { 
       write(query_intro()) ;
       return 1;
      }   
      
    if(str=="index"||str=="索引")   
      { 
       write(query_index()) ;
       return 1;
      }   
    else
      {
        if( sscanf(str,"%s %d",arg,page_no)==2 )
           {
             if(lower_case(arg) == "page" ) 
                write(page_contain(page_no)) ;    
            }
        else    
           { 
             if(lower_case(str)=="page")
                write("你想读那一页 ??\n" ) ;
             else
               return notify_fail("你想读什麽 ??\n") ;     
            }
      }  
    return 1 ;     
}

int view_closet(string arg)
{
  write(
"   你在书柜中翻了翻, 发现除了一本叫『 针灸治要 』的书(book)以外,其於\n"
"大多残缺不全了。\n"
 )  ;
  return 1 ;
}
