</php
/**
 * @author 
 *   Lucian NEAG (Luxian)
 *
 * @created 
 *   2012-11-08
 *
 * The solution was inspired by this topic:
 * 	http://stackoverflow.com/questions/1783089/array-splice-for-associative-arrays
 */


/**
 * Insert values in a associative array at a given position
 *
 * @param array $array
 *   The array in which you want to insert
 * @param array $values
 *   The key => values you want to insert
 * @param string $pivot
 *   The key position to use as insert position.
 * @param string $position
 *   Where to insert the values relative to given $position.
 *   Allowed values: 'after' - default or 'before'
 *
 * @return array
 *   The resulted array with $values inserted a given position
 */
function array_insert_at_position($array, $values, $pivot, $position = 'after'){
  $offset = 0;
  foreach($array as $key => $value){
    ++$offset;
    if ($key == $pivot){
      break;
    }
  }

  if ($position == 'before'){
    --$offset;
  }

  return
    array_slice($array, 0, $offset, TRUE)
    + $values
    + array_slice($array, $offset, NULL, TRUE)
  ;
}

