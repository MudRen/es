#include <mudlib.h>
#include "/d/healer/healer.h"

#define part ({"������λ","ͷ��","����","��ǰ","����","����","����","����","�Ȳ�"})

#define dead ({"����","����","����","����","���","��̨","�ٻ�" })
#define dead_part ({ ({14,0}),({14,3}),({3,3}),({14,4}),({13,6}),({13,6}),({13,1}) })

// ��͸ǿ϶��������  
//  so i remove all points contain these 2 words
//                     Indra .. 94.12.10
//
// int *do_check(string tar_point,mapping known_merid)
// int check_allwork(string *acuped_points)
// string query_eff_file(int arg)
// string *now_working(string arg)
// string *query_eff_pts(int no)
// string query_eff_describ(int no)
// string query_effect_c_name(string str)

nomask string *eff_name = ({  "��Ѩ",
                       "����֮��",
                       "�������",
                       "Ǳ�ܼ���",
                       "����Ѫ",
                       "��������",
                       "ȼ������",
                       }) ;


nomask string *eff_describ = ({
          "\t ����Ѩ����Ϊ����Ѫ������֮Ҫ��,�м����롣\n",
          "\t �����Ὣ�����������,ӵ�г������˵�������\n",
          "\t ���Ὣ����׽�������ķ�,���˸�����������ж���\n",
          "\t ������һ��,���Ὣ���Ǳ�ܷ��ӳ���,ʹ�������г������޵ı��֡�\n",
          "\t ���µ�Ѩ���ܼ����³´�л,ʹ�����ܿ�Щ��ԭ��\n",
          "\t ��ЩѨ���ܴ̼�������,ʹ�þ�����Ӽ��С�\n",
          "\t ȼ���������ǽ�������������������������ġ�\n\t ��ȥ���� ? ��,��������\n",
                         }) ;


nomask string *eff_file = ({ "/d/healer/acupuncture/failure",
                      "/d/healer/acupuncture/superpower",
                      "/d/healer/acupuncture/windex",
                      "/d/healer/acupuncture/potential",
                      "/d/healer/acupuncture/speedyhp",
                      "/d/healer/acupuncture/speedysp",
                      "/d/healer/acupuncture/overdrain",
                      }) ;

nomask mapping work = ([ 
          1:  ({ "�Ϲ�","̫��","����","����","����" }) ,
          2:  ({ "����","����Ȫ","����","ί��","����","�縮" }) ,
          3:  ({ "�Ϲ�","ͷά","���","�쾮","����" }) ,
          4:  ({ "�ڹ�","������","���","�Ϲ�","���" }) ,                  
          5:  ({ "����","����","����","ӿȪ","����" }) ,
          6:  ({ "����","ί��","��Ȫ","����","����","��׵","ˮ��" }) ,
                ])  ;
//part ({"������λ","ͷ��","����","��ǰ","����","����","����","����","�Ȳ�"})
nomask mapping wpart = ([
         1: ({ ({2,7}),({12,8}),({14,4}),({6,7}),({1,3}) }) ,
         2: ({ ({11,8}),({11,8}),({2,7}),({7,5}),({2,7}),({13,2}) }) ,
         3: ({ ({2,7}),({3,1}),({11,1}),({10,7}),({13,1}) }) ,
         4: ({ ({9,7}),({4,8}),({10,7}),({2,7}),({8,3}) }) ,
         5: ({ ({7,2}),({9,7}),({11,8}),({8,8}),({5,7}) }) ,
         6: ({ ({7,1}),({7,8}),({5,7}),({13,6}),({1,7}),({13,6}),({13,1}) }) ,
               ])   ;

//  ����Ǽ���Ƿ�Ϊ�й��õ�Ѩ��֮��,��Ҵ�Ų�������ĵ�ȥ��
//  ���õ�Ѩ��
// i ������mapping ��λ��, j ��Ѩ���ھ����е�λ��
// linit_i limit_j �� i j ����Ŀ, part_name ��Ѩ���������λ��
// ok_flag 1 ����Ѩ,2 Ϊ����Ѩ, 3 Ϊ��������Ѩ,0 �򲻴���,3����points.c

nomask int *do_check(string tar_point,string *known_merid)
{
       int i,j,limit_i,limit_j,ok_flag,*part_info,*cur_part,if_know ;
       string point,*temp ;
       
       ok_flag = 0 ;

       if((j = member_array(tar_point,dead)) != -1)
          { 
            ok_flag = 1 ;
            part_info=dead_part[j] ;
           }

       limit_i = sizeof(work) ;

       for(i=1;i<=limit_i;++i)
          { 
            temp = work [i] ;
            limit_j = sizeof(temp);
            
            if(ok_flag == 0 && (j = member_array(tar_point,temp)) != -1)
               {
                     ok_flag = 2 ;
                     cur_part = wpart[i] ;
                     part_info = (int *)cur_part[j] ;
               }
            if(ok_flag!=0) break ;                
          }      
  
  // Following part check if player learned that very meridian
  
       if(ok_flag!=0)
         {
           temp = ALL_POINTS->query_meridians_by_no(part_info[0]) ;
            
           if((if_know = member_array(temp[0],known_merid)) == -1) 
                return ({ ok_flag , -1 }) ;
           else return ({ ok_flag , part_info[1] }) ;
          }
       return ({ ok_flag,1 }) ;      

}

//   ���������������Ѩ�������Ƿ�Ϊ�����õ�Ѩ��
//   ��!work ʱ,��ʾ�������õ�point list ������
//   i ������Ѩ��mapping �е�λ��,j ΪѨ��������λ��,ok_flag ��Ϊreturn ֮��.

nomask int check_allwork(string *acuped_points)
{
     int i,j,numi,numj,ok_flag ;
     string *temp ;
     
     numi = sizeof(work)+1 ;
     ok_flag = 0 ;
     if(!work)
       {
         write("���ϵͳ�ƺ�����Щ����,��ر���ҽ���������ʦ֪����\n");
         return 0 ;
       }
       
     for(i=1;i<numi;i++)
        {                   
           temp = work[i] ;
           numj = sizeof(temp) ;
           if( sizeof(acuped_points) == numj )
             {
             for(j=0;j<numj;j++)
                {
                 if( acuped_points[j] != temp[j] ) break ;
                 if( j == numj-1 ) ok_flag = i ;
                }  
             }
           if(ok_flag!=0) break ;
        }        
//   acupunctured point is not in work list

     return ok_flag ;
}

nomask string query_eff_file(int arg)
{
   return eff_file[arg] ;
}

//  �������е�������֮Ѩ��,�������õ�����

nomask string *now_working(string arg)
{
     int i,j ;
     string *temp ;
     
     j = sizeof(eff_name) ;
          
     if(!arg) return eff_name ;
          
     for( i=0 ; i<j ; i++ )     
        {
          if(arg == eff_name[i])
             { 
                if(i==0) temp = dead  ;
                else temp = work[i] ; 
                break ;
             }     
        }
     return temp ;
}

// query ����Ѩ��Ⱥ��Ѩ������
nomask string *query_eff_pts(int no)
{
   string *pts,*temp ;
   
   if (no==0 || work[no]) {
     pts = ({ eff_name[no] });
   
     if(no==0)
        pts = pts +  dead ;
     else     
        pts = pts + work[no] ;
   }
       
   return pts ;
}

// query ����Ѩ��Ⱥ����������
nomask string query_eff_describ(int no)
{
    return eff_describ[no] ;
}

nomask string query_effect_c_name(string str)
{
     int i,j ;    
    
     for(i=0;i<sizeof(eff_file);i++)
        {
          if(("/d/healer/acupuncture/"+str)==eff_file[i])
               return eff_name[i] ; 
         }
     return "û����Ч��.��Ǣ��ʦDebug.\n";
}

void create()
{
    seteuid(getuid()) ;
}
