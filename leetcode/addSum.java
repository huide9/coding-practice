import java.util.HashMap;
class Solution {
  public int[] twoSum(int[] nums, int target) {
    HashMap<Integer, Integer> mapPair = new HashMap<>();
    int[] res = {0,0};
    int i;
    for (i=0; i<nums.length; i++){
      mapPair.put(nums[i], i);
      System.out.println("mapPair.get(" + nums[i] +") => " + i);
    }
        
    for (i=0; i<nums.length; i++){
      Integer res2 = mapPair.get((target - nums[i]));
      System.out.println("taget->"+target+" nums[i]->"+nums[i]);
      System.out.println("res2=>" + res2);
      if ( (res2 != null) && (res2!= i)){
        res[0]=i;
        res[1]=res2;
        break;
      }
    }
    return res;
  }
}
class addSum{
  public static void main(String[] args){
    int[] nums={3,2,4};
    int target=6;
    Solution sol=new Solution();
    int[] res= sol.twoSum(nums, target);
    for(int i=0;i<res.length;i++){
      System.out.print(res[i]);
    }
  }
}

