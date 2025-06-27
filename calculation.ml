let mean lst =
  let sum = List.fold_left ( + ) 0 lst in
  float_of_int sum /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let len = List.length sorted in
  if len mod 2 = 0 then
    (float_of_int (List.nth sorted (len / 2 - 1)) +. 
     float_of_int (List.nth sorted (len / 2))) /. 2.0
  else
    float_of_int (List.nth sorted (len / 2))

let mode lst =
  let counts = 
    List.fold_left 
      (fun acc x -> 
        match List.assoc_opt x acc with
        | Some count -> (x, count + 1) :: List.remove_assoc x acc
        | None -> (x, 1) :: acc)
      [] lst in
  if List.length counts = List.length lst then
    [] (* All counts are 1, no mode *)
  else
    let max_count = 
      List.fold_left (fun max (_, count) -> if count > max then count else max) 0 counts in
    List.fold_left 
      (fun acc (x, count) -> if count = max_count then x :: acc else acc)
      [] counts

let () =
  let rec read_ints acc =
    try
      let line = read_line () in
      if line = "" then acc
      else read_ints (int_of_string line :: acc)
    with End_of_file -> acc
  in
  print_endline "Enter integers (one per line, empty line to finish):";
  let lst = List.rev (read_ints []) in
  if lst = [] then (
    print_endline "No numbers entered.";
    exit 0
  );
  
  Printf.printf "Mean: %.2f\n" (mean lst);
  Printf.printf "Median: %.2f\n" (median lst);
  
  let modes = mode lst in
  match modes with
  | [] -> print_endline "Mode: No mode (all numbers occur equally)"
  | _ -> 
      print_string "Mode: ";
      List.iter (Printf.printf "%d ") modes;
      print_newline ()